# barkeep::Speedometer


Helper class to measure and display speed of progress.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> double </span>|  <span class="codey">  **[speed](api/Classes/classbarkeep_1_1_speedometer.md#function-speed)**()</span> |
| <span class="codey"> void </span>|  <span class="codey">  **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream * out, const std::string & speed_unit, const std::string & end = " ")</span><br>Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed.  |
| <span class="codey"> void </span>|  <span class="codey">  **[start](api/Classes/classbarkeep_1_1_speedometer.md#function-start)**()</span><br>Start computing the speed based on the amount of change in progress.  |
| <span class="codey"> </span>|  <span class="codey">  **[Speedometer](api/Classes/classbarkeep_1_1_speedometer.md#function-speedometer)**(Progress * progress, double discount)</span><br>Constructor.  |


</span>

## Detailed Description

```cpp
template <typename Progress >
class barkeep::Speedometer;
```

Helper class to measure and display speed of progress. 
## Public Functions Documentation

### function `speed`

```cpp
inline double speed()
```


### function `render_speed`

```cpp
inline void render_speed(
    std::ostream * out,
    const std::string & speed_unit,
    const std::string & end = " "
)
```

Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed. 

### function `start`

```cpp
inline void start()
```

Start computing the speed based on the amount of change in progress. 

### function `Speedometer`

```cpp
inline Speedometer(
    Progress * progress,
    double discount
)
```

Constructor. 

**Parameters**: 

  * **progress** Reference to numeric to measure the change of. 
  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. 


-------------------------------