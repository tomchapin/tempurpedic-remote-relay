# Tempurpedic Remote Relay

This is an experimental hobbyist project, where the goal was to interface my adjustable Tempurpedic Ergo Adjustable Bed
with my home automation system and with my Amazon Echo. Specifically, I wanted to use the bed's "vibrate"
feature as an alarm clock in the morning, however, I figured I might as well wire up all of the other buttons
on the remote, too!

This project was inspired by the one found here:
http://www.quadomated.com/technology/automation/diy-tempurpedic-ergo-adjustable-bed-automation/

Parts used:
- Tempurpedic Ergo Adjustable Bed
- Tempurpedic Ergo Adjustable Bed Remote Control (RF)
- Relay Shield for Particle Photon I²C 16-Channel SPDT 10-Amp (https://www.controleverything.com/content/Relay-Controller?sku=MCP23017_SCR16G5LE_10A)
- Cat5 network cabling
- Project enclosure: Plastic document holder box from Target (like this one: http://www.target.com/p/room-essentials-super-stacker-document-box/-/A-14786976)

Other Miscellaneous Stuff:
- Small Phillips Head Screwdriver
- Soldering Iron and Solder
- Wire Cutter
- Electrical Tape


## Installing the Particle CLI

#### If you've already installed ```spark-cli```, please uninstall it before continuing.
#### Simply type: ```npm uninstall -g spark-cli``` into the command line.

  First, make sure you have [node.js](http://nodejs.org/) installed!

  Next, open a command prompt or terminal, and install by typing:

```sh
$ npm install -g particle-cli
$ particle cloud login
```

  *Note!*  If you have problems running this, make sure you using Terminal / the Command Prompt as an Administator, or try using ```sudo```

```sh
$ sudo npm install -g particle-cli
```
