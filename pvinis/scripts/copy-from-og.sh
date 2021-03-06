#!/usr/bin/env bash
set -Eeuo pipefail


BASE=.
MINE=./pvinis

git rev-parse HEAD > $MINE/scripts/latest-copy-at-commit.txt

# only copy over my files

# user
rsync -r $BASE/users/pvinis $MINE/users/

# ergodox_ez
rsync -r $BASE/keyboards/ergodox_ez/keymaps/pvinis/ $MINE/keyboards/ergodox_ez/keymaps/pvinis

# keebio/iris
rsync -r $BASE/keyboards/keebio/iris/keymaps/pvinis/ $MINE/keyboards/keebio/iris/keymaps/pvinis
