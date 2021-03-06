#!/usr/bin/env bash
set -Eeuo pipefail


BASE=.
MINE=./pvinis

git checkout master
git pull
git rev-parse HEAD > $MINE/latest-copy-at-commit.txt

# skip keyboards, only copy over mine
# skip layouts
# skip users
rsync -r $BASE/ $MINE  \
 --exclude='.git'      \
 --exclude='keyboards' \
 --exclude='layouts'   \
 --exclude='users'

# ergodox_ez
rsync -r $BASE/keyboards/ergodox_ez/ $MINE/keyboards/ergodox_ez \
 --exclude='keymaps'
# rsync -r $BASE/keyboards/ergodox_ez/keymaps/pvinis/ $MINE/keyboards/ergodox_ez/keymaps/pvinis

# keebio/iris
rsync -r $BASE/keyboards/keebio/iris/ $MINE/keyboards/keebio/iris \
 --exclude='keymaps'
# rsync -r $BASE/keyboards/keebio/iris/keymaps/pvinis/ $MINE/keyboards/keebio/iris/keymaps/pvinis
