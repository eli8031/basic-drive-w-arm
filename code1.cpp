float myVariable;

// "when started" hat block
int whenStarted1() {
  Motor3.spinToPosition(100.0, degrees, true); 
  return 0;
}

// "when Controller1 Axis2 changed" hat block
void onevent_Controller1Axis2Changed_0() {
  while (true) {
    if (0.0 < Controller1.Axis2.position()) {
      Motor1.spin(forward);
      Motor2.spin(forward);
    }
    if (0.0 == Controller1.Axis2.position()) {
      Motor1.stop();
      Motor2.stop();
    }
    if (0.0 > Controller1.Axis2.position()) {
      Motor2.spin(reverse);
      Motor1.spin(forward);
    }
    if (0.0 < Controller1.Axis3.position()) {
      Motor3.spin(forward);
    }
    if (0.0 == Controller1.Axis3.position()) {
      Motor2.stop();
    }
    if (0.0 > Controller1.Axis3.position()) {
      Motor3.spin(reverse);
    }
  wait(5, msec);
  }
}

// "when started" hat block
int whenStarted2() {
  while (true) {
    if (135.0 > Motor3.position(degrees)) {
      Motor3.stop();
    }
  wait(5, msec);
  }
  return 0;
}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // register event handlers
  Controller1.Axis2.changed(onevent_Controller1Axis2Changed_0);

  wait(15, msec);
  vex::task ws1(whenStarted2);
  whenStarted1();
}
