# keebs
[![Build crkbd/rev1](https://github.com/pcheng17/keebs/actions/workflows/build-crkbd.yml/badge.svg)](https://github.com/pcheng17/keebs/actions/workflows/build-crkbd.yml)
[![Build keebio/levinson/rev3](https://github.com/pcheng17/keebs/actions/workflows/build-keebio-levinson.yml/badge.svg?branch=main)](https://github.com/pcheng17/keebs/actions/workflows/build-keebio-levinson.yml)

This repository contains the QMK configurations for my keyboards. I chose not to fork and work
within [qmk_firmware](https://github.com/qmk/qmk_firmware) because of how large of a repository it
is. Simple actions such as committing and pushing would take a non-trivial amount of time (on WSL). 
Instead, I store my source files in this repository, with [qmk_firmware](https://github.com/qmk/qmk_firmware)
as a submodule. Then, symlinks to my source files are created within the `qmk_firmware` subdirectory 
by running the `setup.py` script.
