#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/sena/turtle_drive/src/follow_waypoints"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/sena/turtle_drive/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/sena/turtle_drive/install/lib/python2.7/dist-packages:/home/sena/turtle_drive/build/follow_waypoints/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/sena/turtle_drive/build/follow_waypoints" \
    "/usr/bin/python" \
    "/home/sena/turtle_drive/src/follow_waypoints/setup.py" \
    build --build-base "/home/sena/turtle_drive/build/follow_waypoints" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/sena/turtle_drive/install" --install-scripts="/home/sena/turtle_drive/install/bin"
