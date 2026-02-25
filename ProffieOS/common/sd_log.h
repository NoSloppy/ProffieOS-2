#ifndef COMMON_SD_LOG_H
#define COMMON_SD_LOG_H

#ifdef ENABLE_SD

// SDSerialLog: Tees STDOUT to a file on the SD card.
// Usage:
//   sd_serial_log.start("SERIAL.LOG");  // start logging to SD
//   ... (serial output is written to both serial and the file) ...
//   sd_serial_log.stop();               // stop logging, close file
class SDSerialLog : public Print {
public:
  bool start(const char* filename = "SERIAL.LOG") {
    if (active()) {
      STDOUT.println("Already logging.");
      return false;
    }
    file_ = LSFS::OpenForWrite(filename);
    if (!file_) return false;
    saved_output_ = stdout_output;
    stdout_output = this;
    return true;
  }

  void stop() {
    if (!active()) return;
    stdout_output = saved_output_;
    saved_output_ = nullptr;
    file_.close();
  }

  bool active() const { return stdout_output == this; }

  size_t write(uint8_t b) override {
    size_t ret = saved_output_ ? saved_output_->write(b) : 1;
    if (file_) file_.write(&b, 1);
    return ret;
  }

  size_t write(const uint8_t* buffer, size_t size) override {
    size_t ret = saved_output_ ? saved_output_->write(buffer, size) : size;
    if (file_) file_.write(buffer, size);
    return ret;
  }

private:
  Print* saved_output_ = nullptr;
  LSFS::FILE file_;
};

SDSerialLog sd_serial_log;

#endif  // ENABLE_SD

#endif  // COMMON_SD_LOG_H
