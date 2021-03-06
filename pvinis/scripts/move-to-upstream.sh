#!/usr/bin/env bash
set -Eeuo pipefail


BASE=.
MINE=./pvinis


git checkout master
# git checkout pvinis/master
# git merge master

# only copy over my stuff

# users
rsync -r $MINE/users/pvinis/ $BASE/users/pvinis

# ergodox_ez
rsync -r $MINE/keyboards/ergodox_ez/keymaps/pvinis/ $BASE/keyboards/ergodox_ez/keymaps/pvinis

# keebio/iris
rsync -r $MINE/keyboards/keebio/iris/keymaps/pvinis/ $BASE/keyboards/keebio/iris/keymaps/pvinis
