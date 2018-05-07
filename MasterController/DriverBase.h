#ifndef DRIVERBASE_H
#define DRIVERBASE_H

class DriverBase {
public:
    DriverBase();
    DriverBase(const DriverBase& orig);
    virtual ~DriverBase();
private:
    virtual bool SignalConditioner();
};

#endif /* DRIVERBASE_H */

