# barkeep::Speedometer


Helper class to measure and display speed of progress.  [More...](#detailed-description)


`#include <barkeep.h>`

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream & out, [const](api/Classes/classbarkeep_1_1_counter.md) std::string & speed_unit)<br>Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_speedometer.md#function-start)**()<br>Start computing the speed based on the amount of change in progress.  |
| | **[Speedometer](api/Classes/classbarkeep_1_1_speedometer.md#function-speedometer)**([Progress](api/Classes/classbarkeep_1_1_counter.md) & progress, [double](api/Classes/classbarkeep_1_1_counter.md) discount)<br>Constructor.  |


</span>

## Detailed Description

```cpp
template <typenameProgress >
class barkeep::Speedometer;
```

Helper class to measure and display speed of progress. 
## Public Functions Documentation

### function render_speed

```cpp
inline size_t render_speed(
    std::ostream & out,
    const std::string & speed_unit
)
```

Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed. 

### function start

```cpp
inline void start()
```

Start computing the speed based on the amount of change in progress. 

### function Speedometer

```cpp
inline Speedometer(
    Progress & progress,
    double discount
)
```

Constructor. 

**Parameters**: 

  * **progress** Reference to numeric to measure the change of. 
  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. 


-------------------------------

Updated on 2023-12-02 at 13:34:20 -0500