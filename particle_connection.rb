require_relative 'naughty_ssl_fix'
require 'yaml'
require 'particle'
require 'pry'

def config_particle
  @config_particle ||= YAML.load_file('config/particle.yml')
end

def config_auth
  @config_auth ||= YAML.load_file('config/auth.yml')
end

def save_config_auth!
  File.open('config/auth.yml', 'w') do |handler|
    handler.write config_auth.to_yaml
  end
end

def fetch_new_token!
  puts "Attempting to fetch new token..."
  response = Particle.login(config_auth['email_address'], config_auth['password'])
  puts "New token acquired: #{response.token}"
  config_auth['token'] = response.token
  save_config_auth!
end

def client
  @client ||= Particle::Client.new(access_token: config_auth['token'])
end

def device
  @device ||= client.device(config_particle['device_name'])
end

def reset_connection!
  @client = nil
  @device = nil
end

# Connect to device
begin
  raise 'Device not connected!' unless device.connected?
rescue Particle::MissingTokenError, Particle::Unauthorized => e
  puts e.message
  fetch_new_token!
  reset_connection!
  puts "Retrying..."
  retry
end