sudo python3 setup.py --command-packages=stdeb.command bdist_deb sdist_dsc --suite=bionic
debsign -k Bailey\ Wickham deb_dist/polyxdr_0.1-1_source.changes

