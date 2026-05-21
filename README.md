# MalDuinoScripts

A compact collection of **MalDuino Lite and MalDuino Elite HID automation scripts** for learning, testing, and experimenting with USB keyboard/mouse payload behaviour in a controlled lab environment.

This repository is aimed at makers, students, and security learners who want to understand how MalDuino-style scripts are structured, compiled, tested, and documented.

> **Authorisation first:** only run these scripts on devices and systems that you own or have explicit permission to test. HID payloads can type, click, close windows, or disrupt normal input, so use an isolated test machine, VM, or disposable lab setup.

---

## Contents

| Folder / file | Target | What it does | Best use |
|---|---:|---|---|
| `Hello World/lite/lite.ino` | MalDuino Lite | Waits briefly, then types `HelloWorld!` | First successful upload/test payload |
| `Hello World/elite/elite.ino` | MalDuino Elite | Reads a payload text file from SD card and executes supported commands | Reusable Elite payload runner |
| `Hello World/elite/example.txt` | MalDuino Elite | Example script using `DELAY` and `STRING` | SD-card script template |
| `Alt F4 Spammer/Alt F4 Spammer lite/lite.ino` | MalDuino Lite | Repeatedly sends `ALT + F4` in a loop | Lab-only UI automation stress test |
| `Every Key on the keybord at once on a loop/.../lite.ino` | MalDuino Lite | Sends many keys, symbols, arrows, modifiers, and function keys in a loop | Lab-only keyboard input stress test |

---

## Hardware and software

Recommended setup:

- MalDuino Lite or MalDuino Elite
- Arduino IDE or compatible Arduino build workflow
- USB data cable
- A test computer, spare machine, or VM
- For Elite scripts: a prepared SD card containing the selected `.txt` payload file

The sketches include the required local `Keyboard` source files inside their folders. Keep each `.ino` with its matching `Keyboard.cpp` and `Keyboard.h` files when copying or reorganising scripts.

---

## Safe quick start

1. Clone or download the repository.
2. Open the folder for the script you want to inspect.
3. Read the `.ino` file before uploading it.
4. Connect the MalDuino only to a lab/test machine.
5. Open the `.ino` sketch in Arduino IDE.
6. Select the correct board/port for your MalDuino.
7. Compile and upload.
8. Test slowly and keep the device removable in case the payload loops.

For Lite scripts, the payload is usually embedded directly in the `.ino` file. For Elite scripts, the firmware can read commands from text files on the SD card.

---

## MalDuino Lite notes

Lite scripts in this repository are self-contained Arduino sketches. They generally:

- set up keyboard/mouse emulation,
- wait briefly before running,
- execute the embedded payload,
- blink the LED while the sketch loop continues.

Some Lite sketches only run their payload when the onboard button/input condition is active. This makes it easier to upload or connect the device without instantly triggering the script.

---

## MalDuino Elite notes

The Elite `Hello World` sketch works more like a tiny payload interpreter:

- it initialises the SD card,
- reads DIP switch positions,
- builds a script filename such as `0000.txt`, `0001.txt`, etc.,
- opens the matching payload file,
- reads and executes commands line by line.

Example payload:

```txt
DELAY 1000
STRING HelloWorld!
```

Supported command families in the Elite runner include:

- timing commands such as `DELAY`, `DEFAULT_DELAY`, and `DEFAULT_CHAR_DELAY`,
- text output with `STRING`,
- keyboard keys such as `ENTER`, `ESC`, `TAB`, `SPACE`, arrows, `F1`-`F12`, and modifiers,
- mouse movement/click commands such as `MOUSE`, `SCROLL`, `CLICK`, and related mouse actions,
- random range helpers such as `RANDOMMIN` and `RANDOMMAX`,
- simple repeat handling.

---

## Repository structure

```text
MalDuinoScripts/
├── Alt F4 Spammer/
│   └── Alt F4 Spammer lite/
│       ├── Keyboard.cpp
│       ├── Keyboard.h
│       └── lite.ino
├── Every Key on the keybord at once on a loop/
│   └── Every Key on the keybord at once on a loop/
│       ├── Keyboard.cpp
│       ├── Keyboard.h
│       └── lite/
│           └── lite.ino
├── Hello World/
│   ├── elite/
│   │   ├── Keyboard.cpp
│   │   ├── Keyboard.h
│   │   ├── elite.ino
│   │   └── example.txt
│   └── lite/
│       ├── Keyboard.cpp
│       ├── Keyboard.h
│       └── lite.ino
├── LICENSE
└── README.md
```

---

## Script safety checklist

Before running any script:

- Read every line of the payload.
- Confirm it only affects your own test device.
- Avoid using your main computer for destructive or looping payloads.
- Keep important files backed up.
- Use a VM, spare user account, or disposable test environment.
- Know how to stop the test: unplug device, disable USB pass-through, or reset the target session.
- Never use these scripts on public, workplace, school, or third-party systems without written permission.

---

## Good ideas for future improvements

- Rename `keybord` to `keyboard` while keeping a compatibility note for the old folder path.
- Add a `scripts/` folder with cleaner names and one payload per directory.
- Add screenshots or GIFs of safe lab demonstrations.
- Add a `docs/commands.md` file explaining supported Elite commands.
- Add a `docs/troubleshooting.md` file for upload, SD card, and keyboard layout issues.
- Add comments at the top of each sketch explaining what it does and how to stop it.
- Add safer demo payloads, such as opening a text editor and typing a message on a lab machine.
- Add version tags/releases for stable examples.

---

## Troubleshooting

### The script does nothing

- Check that the correct board and port are selected.
- Confirm the upload completed successfully.
- For Lite scripts, check whether the onboard button/input must be pressed.
- For Elite scripts, confirm the SD card is readable and the payload filename matches the DIP switch selection.

### The wrong characters are typed

- Check the target computer keyboard layout.
- Some symbols may vary between UK/US layouts.
- Test with simple `STRING` payloads first.

### The script loops too fast

- Add a longer startup delay.
- Add clear comments and slower `DEFAULT_DELAY` values.
- Test in a VM or blank editor before running anywhere else.

### Upload fails

- Use a known-good USB data cable.
- Re-select the board and port.
- Close other serial monitor/programming tools.
- Keep the sketch folder structure intact so local `Keyboard` files can be found.

---

## Responsible use

This repository is for education, research, and authorised testing. It should help people learn how USB HID automation works and how to defend against untrusted USB devices.

Do not use these scripts to interfere with systems, accounts, data, or devices you do not own or administer.

---

## License

This repository is licensed under **GPL-3.0**. Some included source headers reference original MalDuino-related work by Seytonic/Spacehuhn under MIT-style notices; preserve attribution and check file headers when reusing individual components.

---

## Credits

- MalDuino ecosystem and examples by Seytonic/Spacehuhn
- Duckuino/Dckuino-style parsing references used in generated payload comments
- Repository maintained by `kai9987kai`
