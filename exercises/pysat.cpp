/* #include <mavlink.h>
#include <mavlink_types.h>
#include <mavlink_helpers.h> */
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

bool enable_logging = false;
/*
class essentials{
    public:
        mavlink_connection_t* connect(std::string device = "/dev/ttyACM0", int baud = 115200, bool do_log = false) {
            mavlink_connection_t* master = mavlink_start(device.c_str(), baud, 0);
            mavlink_message_t msg;
            do {
                mavlink_msg_heartbeat_pack(1, 200, &msg, MAV_TYPE_GCS, MAV_AUTOPILOT_INVALID, 0, 0, MAV_STATE_ACTIVE);
                mavlink_send_message(master, &msg);
                usleep(1000000);
            } while (!mavlink_read_message(master, &msg));
            std::cout << "Pysat connected the vehicle successfully." << std::endl;
            if (do_log == true) {
                enable_logging = true;
                configure_logging();
            }
            return master;
        }

        void arm_vehicle(mavlink_connection_t* master) {
            mavlink_command_long_t cmd = {0};
            cmd.command = MAV_CMD_COMPONENT_ARM_DISARM;
            cmd.target_system = master->target_system;
            cmd.target_component = master->target_component;
            cmd.param1 = 1;
            mavlink_msg_command_long_send_struct(master, &cmd);
            mavlink_message_t msg;
            mavlink_motors_armed_t armed;
            do {
                mavlink_read_message(master, &msg);
                mavlink_msg_motors_armed_decode(&msg, &armed);
            } while (!armed.armed);
            std::cout << "Pysat armed the vehicle successfully." << std::endl;
        }

        void disarm_vehicle(mavlink_connection_t* master) {
            mavlink_command_long_t cmd = {0};
            cmd.command = MAV_CMD_COMPONENT_ARM_DISARM;
            cmd.target_system = master->target_system;
            cmd.target_component = master->target_component;
            cmd.param1 = 0;
            mavlink_msg_command_long_send_struct(master, &cmd);
            mavlink_message_t msg;
            mavlink_motors_armed_t armed;
            do {
                mavlink_read_message(master, &msg);
                mavlink_msg_motors_armed_decode(&msg, &armed);
            } while (armed.armed);
            std::cout << "Pysat disarmed the vehicle successfully." << std::endl;
        }
};
*/

class tools{
    public:
        double set_timer() {
            auto start = std::chrono::high_resolution_clock::now();
            // Do some work here
            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> elapsed = end - start;
            double time_elapsed = elapsed.count();
            return time_elapsed;
        }

        std::string create_save_name() {
            auto now = std::chrono::system_clock::now();
            std::time_t now_c = std::chrono::system_clock::to_time_t(now);
            std::tm* now_tm = std::localtime(&now_c);

            std::ostringstream oss;
            oss << "pysat_save_file_"
                << std::setfill('0') << std::setw(2) << now_tm->tm_hour << ":"
                << std::setfill('0') << std::setw(2) << now_tm->tm_min << ":"
                << std::setfill('0') << std::setw(2) << now_tm->tm_sec << ".log";
            return oss.str();
        }
    
    double set_boot_time() {
        auto now = std::chrono::system_clock::now();
        auto boot_time = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
        return static_cast<double>(boot_time);
    }

    void timer(float zaman, mavutil::mavlink_connection* master, int ch1=1500, int ch2=1500, int ch3=1500, int ch4=1500, int ch5=1500, int ch6=1500, int ch7=1500, int ch8=1500) {
        float timer = 0;
        float ilk_zaman = static_cast<float>(clock()) / CLOCKS_PER_SEC;
        while (true) {
            printf("%f\n", timer);
            timer = static_cast<float>(clock()) / CLOCKS_PER_SEC - ilk_zaman;
            if (timer < zaman) {
                drive::override_motor_channels(master, ch1, ch2, ch3, ch4, ch5, ch6, ch7, ch8);
            }
            if (timer >= zaman) {
                break;
            }
        }
    }





}; 


int main(int argc, char const *argv[])
{
    tools tool;
    double timer = tool.set_timer();
    for(int i=0;i< 100; i++)
        std::cout << "hello world" << std::endl;
    double elapsed_time = tool.set_timer() - timer;
    std::cout << "Elapsed time: " << elapsed_time << " seconds" << std::endl;

    /* std::string save_name = tool.create_save_name();
    std::cout << "Saving data to " << save_name << std::endl;
    // Do some work here
    // Save data to the file */

    double current_time = tool.set_boot_time();
    std::cout << "Current time: " << current_time << std::endl;

    return 0;
}
