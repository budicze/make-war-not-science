#!/bin/sh

openssl aes-256-cbc -K $encrypted_3f2407c008a5_key -iv $encrypted_3f2407c008a5_iv -in .key.enc -out .key -d

sftp -oStrictHostKeyChecking=no -i .key  -b - xbudai00@merlin.fit.vutbr.cz <<EOF
mkdir /homes/eva/xb/xbudai00/builds/${TRAVIS_BUILD_NUMBER}
EOF

case "${os}" in
  linux32)
    sftp -oStrictHostKeyChecking=no -i .key  -b - xbudai00@merlin.fit.vutbr.cz <<EOF
put buildroot.i386/MakeWarNotScience /homes/eva/xb/xbudai00/builds/${TRAVIS_BUILD_NUMBER}/MakeWarNotScience-linux32
EOF
    ;;
  linux64)
	sftp -oStrictHostKeyChecking=no -i .key  -b - xbudai00@merlin.fit.vutbr.cz <<EOF
put MakeWarNotScience /homes/eva/xb/xbudai00/builds/${TRAVIS_BUILD_NUMBER}/MakeWarNotScience-linux32
EOF
    ;;
esac