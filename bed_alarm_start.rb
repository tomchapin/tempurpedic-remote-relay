require_relative 'particle_connection'

# Script
50.times do
  puts 'Vibrating bed for approximately 2 seconds...'
  @device.function('startAlarm', '')
  sleep(2)
  puts 'Stopping vibration...'
  @device.function('stopAlarm', '')
  sleep(1)
end