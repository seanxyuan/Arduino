#include <ros.h>
#include <ros_essentials_cpp/Arduino_O.h>

ros::NodeHandle nh;

ros_essentials_cpp::Arduino_O arduino_o;
ros::Publisher arduino_output("Arduino_Output_topic", &arduino_o);

void setup()
{
  nh.initNode();
  nh.advertise(arduino_output);
}

void loop()
{
  arduino_o.relay1Error = random(2);
  arduino_o.relay2Error = random(2);
  arduino_o.relay3Error = random(2);
  arduino_o.relay4Error = random(2);
  arduino_output.publish( &arduino_o );
  nh.spinOnce();
 
  delay(100);
}
