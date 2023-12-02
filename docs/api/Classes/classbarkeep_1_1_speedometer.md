# barkeep::Speedometer


 [More...](#detailed-description)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream & out, [const](api/Classes/classbarkeep_1_1_counter.md) std::string & speed_unit) |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_speedometer.md#function-start)**() |
| | **[Speedometer](api/Classes/classbarkeep_1_1_speedometer.md#function-speedometer)**([Progress](api/Classes/classbarkeep_1_1_counter.md) & progress, [double](api/Classes/classbarkeep_1_1_counter.md) discount) |


</span>

## Detailed Description

```cpp
template <typenameProgress >
class barkeep::Speedometer;
```

## Public Functions Documentation

### function render_speed

```cpp
inline size_t render_speed(
    std::ostream & out,
    const std::string & speed_unit
)
```


### function start

```cpp
inline void start()
```


### function Speedometer

```cpp
inline Speedometer(
    Progress & progress,
    double discount
)
```


-------------------------------

Updated on 2023-12-01 at 22:33:53 -0500