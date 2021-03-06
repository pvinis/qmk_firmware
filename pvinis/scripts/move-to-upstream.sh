#!/usr/bin/env bash
set -Eeuo pipefail


BASE=~/Source/contrib/qmk_firmware
MINE=~/Source/pvinis/my_qmk_firmware

cd $BASE

git checkout master
git pull
git checkout pvinis/master
git pull
git merge master

# skip keyboards, only copy over mine
# skip layouts
# skip users
# rsync -r $BASE/ $MINE  \
#  --exclude='.git'      \
#  --exclude='keyboards' \
#  --exclude='layouts'   \
#  --exclude='users'

# users
rsync -r $MINE/users/pvinis/ $BASE/users/pvinis

# ergodox_ez
rsync -r $MINE/keyboards/ergodox_ez/keymaps/pvinis/ $BASE/keyboards/ergodox_ez/keymaps/pvinis

# keebio/iris
rsync -r $MINE/keyboards/keebio/iris/keymaps/pvinis/ $BASE/keyboards/keebio/iris/keymaps/pvinis
