# KBD75 Settup

The KBD75 is a 75% keyboard that is created and sold by [KBDFans](https://kbdfans.myshopify.com/). This repository explains how I setup my KBD75 (R3).

![Dolch KBD75](https://github.com/krddr/kbd75/blob/master/images/keyboard-layout.png)

## Programming

Start off by going to [qmkeyboard.cn](qmkeyboard.cn). This is a clone of [qmk.sized.io](qmk.sized.io) with support for the KBD75. Follow the steps in the [Programing Guide](http://github.com/krddr/kbd75/docs/kbd75_programing.pdf) to edit the key layout to your liking.

The [QMK Documentation](https://docs.qmk.fm/keycodes.html) has a great description of each keycode. I found this [qmk-firmware Readme](https://github.com/joecridge/qmk-firmware) had an easy to read description of all of the different function types, like MO, LT, LG, etc.

### Downloading your .hex

If you can get everything you want out of the UI, then generate a .hex by selecting **Compile** and then **Download .hex**.

### Building your own .hex

If you aren't able to get the exact behavior you like out of the UI editor, you can download the source and build the firmware yourself. To download the source again go to **Compile**, but this time select **Download .zip**. The downloaded .zip file is the souce code that can be used to compile your own .hex. The keymap.c file in the downloaded .zip will already be configured to match the layout that you've configured in the UI.

I found it useful to look at [Clueboard's keymap.c](https://github.com/qmk/qmk_firmware/blob/master/keyboards/clueboard/keymaps/default/keymap.c), and the [Keymap Overview](https://docs.qmk.fm/keymap.html) for examples.

I built my .hex on Linux using by following the [Build Environment Setup](https://docs.qmk.fm/build_environment_setup.html). Note that the source code that is downloaded from qmkeyboard.cn doesn't include tests; test compile will fail, but that can be ignored.

### Flashing with your .hex

Download the [QMK Flasher](https://github.com/qmk/qmk_flasher/releases/tag/v0.5.0/). I used version 0.5.0 for Windows in a virtual machine. I used Windows 10 running in VMware Fusion, and had no issues.

Setting the keyboard into bootloader mode is done either by pressing Fn1+Backspace, or by using a hardware button on the bottom of the keyboard. One thing that tripped me up is that I mapped Backspace to a different location, and bootloader mode isn't based on where Backspace is currently programmed. It's always where the ANSI Backspace button is located.

## Layout

I normally use a 60% or 65%, so I programmed the default layer of my 75% to have a similar layout. The top row is only bonus keys, and everything can be done with the bottom 65%. See the double ESC key!

    /* 0: Default layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |Esc^Fn1| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| F11| F12|PrtS|ScrL| Ins |
     * |-----------------------------------------------------------------------------------|
     * |Esc^~|  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |  - |  = |   \ |   ` | Home|
     * |-----------------------------------------------------------------------------------|
     * | Tab  |  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P |  [ |  ] | Back^Del | PgUp|
     * |-----------------------------------------------------------------------------------|
     * |  Ctrl   |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ; |  ' |    Return  | PgDn|
     * |-----------------------------------------------------------------------------------|
     * |  Shift    |  Z |  X |  C |  V |  B |  N |  M |  , |  . |  / |   Shift  |    | End |
     * |-----------------------------------------------------------------------------------|
     * |  Fn1 |  Sup |  Alt |            Space            |   Alt |  Ctrl |     |    |     |
     * `-----------------------------------------------------------------------------------'
     */

The first function layer is mostly used for volume adjustment, and Vim-style direction keys. With the extra available top row, I also added the ability to switch workspaces on my Linux desktop (see GUI1-GUI9).

    /* 1: Function layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |       |GUI1|GUI2|GUI3|GUI4|GUI5|GUI6|GUI7|GUI8|GUI9|    |    |    |    |    | Mute|
     * |-----------------------------------------------------------------------------------|
     * |  `  |    |    |    |    |    |    |    |    |    |    |    |    |     |     | Mute|
     * |-----------------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    | Delete   | Vol+|
     * |-----------------------------------------------------------------------------------|
     * |         |    |    |    |    |    |Left| Dn | Up |Righ|    |    |            | Vol-|
     * |-----------------------------------------------------------------------------------|
     * |           |    |    |    |    |    |    |    |    |    |    |          |PgUp|     |
     * |-----------------------------------------------------------------------------------|
     * |  Fn1 |  Fn2 |      |                             |       |       | Home|PgDn| End |
     * `-----------------------------------------------------------------------------------'
     */

The second function layer is RGB LED control.

    /* 2: Control layer
     *
     * ,-----------------------------------------------------------------------------------.
     * |       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | Mode|
     * |-----------------------------------------------------------------------------------|
     * |     |    |    |    |    |    |    |    |    |    |    |    |    |     |     | Mode|
     * |-----------------------------------------------------------------------------------|
     * |      |    |    |    |    |    |    |    |    |    |    |    |    |          | VA+ |
     * |-----------------------------------------------------------------------------------|
     * |         |    |    |    |    |    |    |    |    |    |    |    |            | VA- |
     * |-----------------------------------------------------------------------------------|
     * |           |    |    |    |    |    |    |    |    |    |    |          |Sat+|     |
     * |-----------------------------------------------------------------------------------|
     * |      |  Fn2 |      |          RGB Toggle         |       |       | Hue+|Sat-| Hue-|
     * `-----------------------------------------------------------------------------------'
     */
