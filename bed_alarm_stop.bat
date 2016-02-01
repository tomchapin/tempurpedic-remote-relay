@echo off
taskkill.exe /F /IM ruby.exe
bundle exec ruby bed_alarm_stop.rb