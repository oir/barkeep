# barkeep::Counter


Monitors and displays a single numeric variable.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, [const](api/Classes/classbarkeep_1_1_counter.md)[CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md) & cfg ={})<br>Constructor.  |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([const](api/Classes/classbarkeep_1_1_counter.md)[Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**()<br>Write the value of progress to the output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**() override<br>Write the value of progress with the message to the output stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override<br>Default interval in which the display is refreshed, if interval() is not invoked.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_counter.md#function-start)**() override<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(std::ostream * out =&std::cout) |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [Progress](api/Classes/classbarkeep_1_1_counter.md) * | **[progress_](api/Classes/classbarkeep_1_1_counter.md#variable-progress_)**  |
| std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > > | **[speedom_](api/Classes/classbarkeep_1_1_counter.md#variable-speedom_)**  |
| std::string | **[speed_unit_](api/Classes/classbarkeep_1_1_counter.md#variable-speed_unit_)**  |
| std::stringstream | **[ss_](api/Classes/classbarkeep_1_1_counter.md#variable-ss_)**  |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, [bool](api/Classes/classbarkeep_1_1_counter.md) complete =[false](api/Classes/classbarkeep_1_1_counter.md), std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()<br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display.  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const<br>Display the message to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()<br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| std::ostream * | **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**  |
| std::unique_ptr< std::thread > | **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**  |
| std::condition_variable | **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**  |
| std::mutex | **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**  |
| std::atomic< [bool](api/Classes/classbarkeep_1_1_counter.md) > | **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**  |
| Duration | **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**  |
| std::string | **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**  |
| std::string | **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**  |
| [bool](api/Classes/classbarkeep_1_1_counter.md) | **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**  |


</span>

**Friends inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [class](api/Classes/classbarkeep_1_1_counter.md) | **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**([Composite](api/Classes/classbarkeep_1_1_composite.md) )  |


</span>


## Detailed Description

```cpp
template <typenameProgress  =size_t>
class barkeep::Counter;
```

Monitors and displays a single numeric variable. 
## Public Functions Documentation

### function Counter

```cpp
inline Counter(
    Progress * progress,
    constCounterConfig & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored and displayed 
  * **cfg** [Counter](api/Classes/classbarkeep_1_1_counter.md) parameters 


### function Counter

```cpp
inline Counter(
    constCounter< Progress > & other
)
```


### function Counter

```cpp
inline Counter(
    Counter< Progress > && other
)
```


### function ~Counter

```cpp
inline ~Counter()
```


### function clone

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [barkeep::AsyncDisplay::clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


## Protected Functions Documentation

### function render_counts_

```cpp
inline void render_counts_()
```

Write the value of progress to the output stream. 

### function render_

```cpp
inline virtual void render_() override
```

Write the value of progress with the message to the output stream. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```

Default interval in which the display is refreshed, if interval() is not invoked. 

**Return**: default interval 

**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### function start

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [barkeep::AsyncDisplay::start](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### function Counter

```cpp
inline Counter(
    std::ostream * out =&std::cout
)
```


## Protected Attributes Documentation

### variable progress_

```cpp
Progress * progress_ = nullptr;
```


### variable speedom_

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


### variable speed_unit_

```cpp
std::string speed_unit_ = "it/s";
```


### variable ss_

```cpp
std::stringstream ss_;
```


-------------------------------

Updated on 2024-02-18 at 11:29:07 -0500