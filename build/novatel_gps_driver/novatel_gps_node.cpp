#include <boost/shared_ptr.hpp>
#include "ros/ros.h"
#include "nodelet/nodelet.h"

namespace novatel_gps_driver
{
  boost::shared_ptr<nodelet::Nodelet> createNovatelGpsNodelet();
}  // namespace novatel_gps_driver

int main(int argc, char **argv)
{
  ros::init(argc, argv, "novatel_gps_node");
  nodelet::M_string remap(ros::names::getRemappings());;
  nodelet::V_string my_argv;
  boost::shared_ptr<nodelet::Nodelet> n = novatel_gps_driver::createNovatelGpsNodelet();
  n->init(ros::this_node::getName(), remap, my_argv);
  ros::spin();
  return 0;
}
