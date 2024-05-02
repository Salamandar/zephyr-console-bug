cmake_minimum_required(VERSION 3.20.0)

# set(BOARD nucleo_l476rg)
set(BOARD nrf52840dk/nrf52840)
# set(DTC_OVERLAY_FILE app.overlay)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(l4z)

target_sources(app PRIVATE src/main.c)
