#! /bin/bash

# run from the top directory (_not_ from ./docs) as `./docs/make-docs.sh`

set -ex

# run doxygen and doxybook

rm -rf docs/api/*  # remove previous generation
doxygen docs/Doxyfile  # generate xml from C++ code
doxybook2 -i xml -o docs/api --config docs/config.json --templates docs/template/  # generate md from xml
rm -rf xml  # remove intermediate xml

# make some additions to play nicely with docsify

# make a landing page for API docs
cat docs/api/Namespaces/README.md \
  docs/api/Classes/README.md \
  > docs/api/README.md

# add docsify-ignore to landing page to avoid docsify tinkering with sidebar
sed -i '' 's/# Namespaces/# Namespaces <!-- {docsify-ignore-all} -->/g' docs/api/README.md

# because of concat, the footer is repeated. remove the first one
perl -0777 -i'' -pe 's/[-]+\n\nUpdated on .+\n//' docs/api/README.md