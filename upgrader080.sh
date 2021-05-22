#!/bin/sh
yarn add https://github.com/rickyvetter/upgrade-reason-react\#0.7.0-to-0.8.0
cat package.json | grep upgrade-reason-react

find src -name "*.re" | npx upgrade-reason-react
yarn add bs-platform@0.8.0 -D
yarn add reason-react@0.8.0
cat package.json | grep bs-platform
cat package.json | grep reason-react

yarn remove upgrade-reason-react
git add . && git commit -m "rickyvetter/upgrade-reason-react\#0.7.0-to-0.8.0"
