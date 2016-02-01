require_relative 'particle_connection'

# Script
puts 'Raising head of bed...'
@device.function('turnOnRelay', '1')
sleep 25
@device.function('turnOffRelay', '1')