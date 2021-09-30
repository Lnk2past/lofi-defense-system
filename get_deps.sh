#!/bin/bash

pushd ~
git clone git@github.com:Lnk2past/malen.git
git clone git@github.com:Lnk2past/malen-bokeh.git
git clone --single-branch --branch 8.0.1 git@github.com:fmtlib/fmt.git
git clone --depth 1 --branch v3.10.2 git@github.com:nlohmann/json.git
popd

