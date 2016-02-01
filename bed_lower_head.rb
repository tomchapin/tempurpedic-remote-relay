require_relative 'particle_connection'

# Script
puts 'Lowering head of bed...'
@device.function('turnOnRelay', '2')
sleep 25
@device.function('turnOffRelay', '2')