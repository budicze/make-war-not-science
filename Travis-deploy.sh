#!/bin/sh

openssl aes-256-cbc -K $encrypted_3f2407c008a5_key -iv $encrypted_3f2407c008a5_iv -in .key.enc -out .key -d

chmod 0600 .key


case "${os}" in
  linux32)
	sftp -oStrictHostKeyChecking=no -i .key  -b - ondrej.budai@bastl1.rss.tul.cz <<EOF
put buildroot.i386/MakeWarNotScience /mnt/home/ondrej.budai/builds/${TRAVIS_BUILD_NUMBER}-linux32
EOF
    ;;
  linux64)
	sftp -oStrictHostKeyChecking=no -i .key  -b - ondrej.budai@bastl1.rss.tul.cz <<EOF
put MakeWarNotScience /mnt/home/ondrej.budai/builds/${TRAVIS_BUILD_NUMBER}-linux64
EOF
    ;;
esac