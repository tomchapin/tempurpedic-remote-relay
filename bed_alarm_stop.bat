@echo off
taskkill.exe /F /IM ruby.exe
pause
bundle exec ruby bed_alarm_stop.rb