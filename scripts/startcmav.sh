#/bin/bash

python loadconfig.py ../example/ground.json &
../build/cmavnode -H 8000 -r ~/catkin_ws/src/New_GUI/media/roi

python loadconfig.py ../example/groundsafe.json &
../build/cmavnode -H 8000 -r ~/catkin_ws/src/New_GUI/media/roi