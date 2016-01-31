require 'yaml'
require 'particle'
require 'pry'

def config
  @config ||= YAML.load_file('config.yml')
end

def auth_config
  @auth_config ||= YAML.load_file('auth.yml')
end

def fetch_new_token!
  puts "Attempting to fetch new token"
  response = Particle.login(auth_config['email_address'], auth_config['password'])
  puts "New token acquired: #{response.token}"
  auth_config['token'] = response.token
  save_auth_config!
end

def save_auth_config!
  File.open('auth.yml', 'w') do |handler|
    handler.write auth_config.to_yaml
  end
end

def client
  @client ||= Particle::Client.new(access_token: auth_config['token'])
end

def device
  @device ||= client.device(config['photon_device_name'])
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
  retry
end