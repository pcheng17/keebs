# keebs

This repository contains the QMK configurations for my keyboards. I chose not to fork and work
within [qmk_firmware](https://github.com/qmk/qmk_firmware) because of how large of a repository it
is. Simple actions such as committing and pushing would take a non-trivial amount of time. Instead,
I store my source files in this repository, with [qmk_firmware](https://github.com/qmk/qmk_firmware)
as a submodule. Then, symlinks to my source files are created within the `qmk_firmware` subdirectory.
