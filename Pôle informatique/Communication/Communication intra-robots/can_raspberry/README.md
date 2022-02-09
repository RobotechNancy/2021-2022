pour crée un bus can virtuel (vcan0) :
  - sudo modprobe vcan
  - sudo ip link add dev vcan0 type vcan
  - sudo ip link set up vcan0
