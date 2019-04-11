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

echo_and_run cd "/home/nishanth/TurtleStuff/turtle_drive/src/ros_controllers/rqt_joint_trajectory_controller"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/nishanth/TurtleStuff/turtle_drive/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/nishanth/TurtleStuff/turtle_drive/install/lib/python2.7/dist-packages:/home/nishanth/TurtleStuff/turtle_drive/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/nishanth/TurtleStuff/turtle_drive/build" \
    "/usr/bin/python" \
    "/home/nishanth/TurtleStuff/turtle_drive/src/ros_controllers/rqt_joint_trajectory_controller/setup.py" \
    build --build-base "/home/nishanth/TurtleStuff/turtle_drive/build/ros_controllers/rqt_joint_trajectory_controller" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/nishanth/TurtleStuff/turtle_drive/install" --install-scripts="/home/nishanth/TurtleStuff/turtle_drive/install/bin"
