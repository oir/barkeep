# barkeep::CounterDisplay


Monitors and displays a single numeric variable.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[CounterDisplay](api/Classes/classbarkeep_1_1_counter_display.md#function-counterdisplay)**(Progress * progress, const [CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md) & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[~CounterDisplay](api/Classes/classbarkeep_1_1_counter_display.md#function-~counterdisplay)**()</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[render_counts_](api/Classes/classbarkeep_1_1_counter_display.md#function-render_counts_)**(const std::string & end = " ")</span><br>Write the value of progress to the output stream.  |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_counter_display.md#function-render_)**(bool  = false, const std::string & end = " ") override</span><br>Write the value of progress with the message to the output stream.  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_counter_display.md#function-default_interval_)**(bool no_tty) const</span><br>Default interval in which the display is refreshed, if not provided.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_counter_display.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> Progress * </span> | <span class="codey"> **[progress_](api/Classes/classbarkeep_1_1_counter_display.md#variable-progress_)**</span>  |
| <span class="codey"> std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< Progress > > </span> | <span class="codey"> **[speedom_](api/Classes/classbarkeep_1_1_counter_display.md#variable-speedom_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit_](api/Classes/classbarkeep_1_1_counter_display.md#variable-speed_unit_)**</span>  |
| <span class="codey"> std::stringstream </span> | <span class="codey"> **[ss_](api/Classes/classbarkeep_1_1_counter_display.md#variable-ss_)**</span>  |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"></span>| <span class="codey">**[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(std::ostream * out = &std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval = [Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.5}, const std::string & message = "", const std::string & format = "", bool no_tty = false)</span> |
| <span class="codey"></span>| <span class="codey">**[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(const [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & ) = delete</span> |
| <span class="codey">[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & </span>| <span class="codey">**[operator=](api/Classes/classbarkeep_1_1_base_display.md#function-operator=)**(const [BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md) & ) = delete</span> |
| <span class="codey">virtual </span>| <span class="codey">**[~BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-~basedisplay)**()</span> |
| <span class="codey">virtual void </span>| <span class="codey">**[show](api/Classes/classbarkeep_1_1_base_display.md#function-show)**()</span><br>Start the display.  |
| <span class="codey">virtual void </span>| <span class="codey">**[done](api/Classes/classbarkeep_1_1_base_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey">std::ostream & </span>| <span class="codey">**[out](api/Classes/classbarkeep_1_1_base_display.md#function-out)**() const</span><br>Output stream to write to.  |
| <span class="codey">bool </span>| <span class="codey">**[running](api/Classes/classbarkeep_1_1_base_display.md#function-running)**() const</span><br>Return true if the display is running.  |


</span>

**Protected Functions inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">long </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_base_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey"></span>| <span class="codey">**[BaseDisplay](api/Classes/classbarkeep_1_1_base_display.md#function-basedisplay)**(std::shared_ptr< [AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md) > displayer)</span> |


</span>

**Protected Attributes inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">std::shared_ptr< [AsyncDisplayer](api/Classes/classbarkeep_1_1_async_displayer.md) > </span>| <span class="codey">**[displayer_](api/Classes/classbarkeep_1_1_base_display.md#variable-displayer_)** </span><br>shared across components of a composite display  |
| <span class="codey">std::string </span>| <span class="codey">**[message_](api/Classes/classbarkeep_1_1_base_display.md#variable-message_)** </span> |
| <span class="codey">std::string </span>| <span class="codey">**[format_](api/Classes/classbarkeep_1_1_base_display.md#variable-format_)** </span> |


</span>

**Friends inherited from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | <span class="codey">**[CompositeDisplay](api/Classes/classbarkeep_1_1_base_display.md#friend-compositedisplay)**</span>  |
| class | <span class="codey">**[AsyncDisplayer](api/Classes/classbarkeep_1_1_base_display.md#friend-asyncdisplayer)**</span>  |


</span>


## Detailed Description

```cpp
template <typename Progress  =size_t>
class barkeep::CounterDisplay;
```

Monitors and displays a single numeric variable. 
## Public Functions Documentation

### function `CounterDisplay`

```cpp
inline CounterDisplay(
    Progress * progress,
    const CounterConfig & cfg = {}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored and displayed 
  * **cfg** Counter parameters 


### function `~CounterDisplay`

```cpp
inline ~CounterDisplay()
```


## Protected Functions Documentation

### function `render_counts_`

```cpp
inline void render_counts_(
    const std::string & end = " "
)
```

Write the value of progress to the output stream. 

### function `render_`

```cpp
inline virtual long render_(
    bool  = false,
    const std::string & end = " "
) override
```

Write the value of progress with the message to the output stream. 

**Reimplements**: [`barkeep::BaseDisplay::render_`](api/Classes/classbarkeep_1_1_base_display.md#function-render_)


### function `default_interval_`

```cpp
inline Duration default_interval_(
    bool no_tty
) const
```

Default interval in which the display is refreshed, if not provided. 

### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::BaseDisplay::start`](api/Classes/classbarkeep_1_1_base_display.md#function-start)


## Protected Attributes Documentation

### variable `progress_`

```cpp
Progress * progress_ = nullptr;
```


### variable `speedom_`

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


### variable `speed_unit_`

```cpp
std::string speed_unit_ = "it/s";
```


### variable `ss_`

```cpp
std::stringstream ss_;
```


-------------------------------