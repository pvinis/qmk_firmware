#!/usr/bin/env bash
set -Eeuo pipefail


BASE=.
MINE=./pvinis

git checkout master
git pull
git rev-parse HEAD > $MINE/latest-copy-at-commit.txt

# only copy over my files
# ergodox_ez
rsync -r $BASE/keyboards/ergodox_ez/keymaps/pvinis/ $MINE/keyboards/ergodox_ez/keymaps/pvinis

# keebio/iris
rsync -r $BASE/keyboards/keebio/iris/keymaps/pvinis/ $MINE/keyboards/keebio/iris/keymaps/pvinis
