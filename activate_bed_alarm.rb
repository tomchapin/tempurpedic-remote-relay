require_relative 'particle_connection'

# Script
3.times do
  puts 'Vibrating bed for approximately 2 seconds...'
  @device.function('alarm', '2')
end