CAMERA=$(./find_camera.py --name Rocketfish)

echo Camera index: $CAMERA

v4l2-ctl -d $CAMERA -c focus_absolute=20
v4l2-ctl -d $CAMERA -c saturation=64
v4l2-ctl -d $CAMERA -c exposure_absolute=70

