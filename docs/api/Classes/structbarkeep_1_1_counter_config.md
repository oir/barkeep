# barkeep::CounterConfig


[Counter](api/Classes/classbarkeep_1_1_counter.md) parameters. 


`#include <barkeep.h>`

## Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out](api/Classes/structbarkeep_1_1_counter_config.md#variable-out)** <br>output stream  |
| std::string | **[format](api/Classes/structbarkeep_1_1_counter_config.md#variable-format)** <br>format string to format entire counter  |
| std::string | **[message](api/Classes/structbarkeep_1_1_counter_config.md#variable-message)** <br>message to display with the counter  |
| std::optional< double > | **[speed](api/Classes/structbarkeep_1_1_counter_config.md#variable-speed)** <br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| std::string | **[speed_unit](api/Classes/structbarkeep_1_1_counter_config.md#variable-speed_unit)** <br>unit of speed text next to speed interval in which the counter is refreshed  |
| std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > | **[interval](api/Classes/structbarkeep_1_1_counter_config.md#variable-interval)**  |
| bool | **[no_tty](api/Classes/structbarkeep_1_1_counter_config.md#variable-no_tty)** <br>no-tty mode if true (no \r, slower default refresh)  |
| bool | **[show](api/Classes/structbarkeep_1_1_counter_config.md#variable-show)** <br>show the counter immediately after construction  |


</span>

## Public Attributes Documentation

### variable out

```cpp
std::ostream * out = &std::cout;
```

output stream 

### variable format

```cpp
std::string format = "";
```

format string to format entire counter 

### variable message

```cpp
std::string message = "";
```

message to display with the counter 

### variable speed

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

### variable speed_unit

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed interval in which the counter is refreshed 

### variable interval

```cpp
std::variant< Duration, double > interval = Duration{0.};
```


### variable no_tty

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

### variable show

```cpp
bool show = true;
```

show the counter immediately after construction 

-------------------------------

Updated on 2024-03-28 at 22:58:08 -0400