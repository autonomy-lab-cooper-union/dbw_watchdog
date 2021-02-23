# IGVC DBW Team's Watchdog

![Build Action](https://github.com/autonomy-lab-cooper-union/dbw_watchdog/actions/workflows/c-cpp.yml/badge.svg)

The watchdog is a program that runs on the Pi, along with the UI software. It 
is designed to monitor the rest of the car in a central place and be the 
authority for mode changes.

The watchdog is composed of a core and main thread, which starts module threads which monitor various aspects
of the car.
