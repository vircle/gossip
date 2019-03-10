
Debian
====================
This directory contains files used to package gossipd/gossip-qt
for Debian-based Linux systems. If you compile gossipd/gossip-qt yourself, there are some useful files here.

## gossip: URI support ##


gossip-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install gossip-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your gossipqt binary to `/usr/bin`
and the `../../share/pixmaps/gossip128.png` to `/usr/share/pixmaps`

gossip-qt.protocol (KDE)

