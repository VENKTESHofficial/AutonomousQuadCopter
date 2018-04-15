#ifndef TRAJECTORYPLANNER_H
#define TRAJECTORYPLANNER_H
#include <stdint.h>
#include "BaseModule.h"
// TrajectoryPlanner class
// Designs the operation path looking for the incoming restrictions like obstacles
// boundary constraints(position, speed, acceleration, time, etc..)
class TrajectoryPlanner : public BaseModule{
public:
    TrajectoryPlanner();
    TrajectoryPlanner(const TrajectoryPlanner& orig);
    virtual ~TrajectoryPlanner();
private:

};

#endif /* TRAJECTORYPLANNER_H */

