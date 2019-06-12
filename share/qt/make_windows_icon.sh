#!/bin/bash
# create multiresolution windows icon
#mainnet
ICON_SRC=../../src/qt/res/icons/gossip.png
ICON_DST=../../src/qt/res/icons/gossip.ico
convert ${ICON_SRC} -resize 16x16 gossip-16.png
convert ${ICON_SRC} -resize 32x32 gossip-32.png
convert ${ICON_SRC} -resize 48x48 gossip-48.png
convert gossip-16.png gossip-32.png gossip-48.png ${ICON_DST}
#testnet
ICON_SRC=../../src/qt/res/icons/gossip_testnet.png
ICON_DST=../../src/qt/res/icons/gossip_testnet.ico
convert ${ICON_SRC} -resize 16x16 gossip-16.png
convert ${ICON_SRC} -resize 32x32 gossip-32.png
convert ${ICON_SRC} -resize 48x48 gossip-48.png
convert gossip-16.png gossip-32.png gossip-48.png ${ICON_DST}
rm gossip-16.png gossip-32.png gossip-48.png
