import os

BASEDIR = os.path.dirname(os.path.abspath(__file__))
QMKDIR = os.path.join(BASEDIR, 'qmk_firmware')

subdirs = os.walk("keyboards")
keymaps = []
for dirpath, dirnames, filenames in subdirs:
    if not dirnames:
        src = os.path.join(BASEDIR, dirpath)
        dst = os.path.join(QMKDIR, dirpath)
        if not os.path.islink(dst):
            os.symlink(src, dst)
