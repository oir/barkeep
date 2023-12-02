# barkeep::Counter


Monitors and displays a single numeric variable.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout)<br>Constructor.  |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([const](api/Classes/classbarkeep_1_1_counter.md)[Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other) |
| | **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_counter.md#function-show)**() override<br>Start displaying the counter.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_counter.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount)<br>Set how to compute speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_counter.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set unit of speed text next to speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_counter.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**(Duration pd)<br>Set interval in which the display is refreshed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_counter.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_counter.md#function-interval) to accept a double argument.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_counter.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**(std::ostream & out)<br>Write the value of progress to the output stream.  |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**(std::ostream & out) override<br>Write the value of progress with the message to the output stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override<br>Default interval in which the display is refreshed, if [interval()](api/Classes/classbarkeep_1_1_counter.md#function-interval) is not invoked.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_counter.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(std::ostream & out =std::cout) |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream & out =std::cout) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([const](api/Classes/classbarkeep_1_1_counter.md)[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other) |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other) |
| virtual | **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**() |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()<br>End the display. This adds a newline to the output stream and stops writing.  |


</span>

**Protected Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()<br>Display everything (message, maybe with animation, progress bar, etc).  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**(std::ostream & out) const<br>Display the message to output stream.  |


</span>

**Protected Attributes inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
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
    std::ostream & out =std::cout
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored and displayed 
  * **out** Output stream to write to 


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


### function show

```cpp
inline virtual void show() override
```

Start displaying the counter. 

**Reimplements**: [barkeep::AsyncDisplay::show](api/Classes/classbarkeep_1_1_async_display.md#function-show)


### function speed

```cpp
inline auto & speed(
    std::optional< double > discount
)
```

Set how to compute speed. 

**Parameters**: 

  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. If discount is `std::nullopt`, speed is not computed. 


**Return**: reference to self 

### function speed_unit

```cpp
inline auto & speed_unit(
    const std::string & msg
)
```

Set unit of speed text next to speed. 

**Parameters**: 

  * **msg** unit of speed 


**Return**: reference to self 

### function message

```cpp
inline auto & message(
    const std::string & msg
)
```

Set message to be displayed. 

**Parameters**: 

  * **msg** Message 


**Return**: reference to self 

### function interval

```cpp
inline auto & interval(
    Duration pd
)
```

Set interval in which the display is refreshed. 

**Parameters**: 

  * **pd** interval as a Duration 


**Return**: reference to self 

### function interval

```cpp
inline auto & interval(
    double pd
)
```

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_counter.md#function-interval) to accept a double argument. 

**Parameters**: 

  * **pd** interval as a double 


**Return**: reference to self 

### function no_tty

```cpp
inline auto & no_tty()
```

Enable no-tty mode. 

**Return**: reference to self 

## Protected Functions Documentation

### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```

Write the value of progress to the output stream. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered value 

### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```

Write the value of progress with the message to the output stream. 

**Parameters**: 

  * **out** output stream to write to 


**Return**: length of the rendered string 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```

Default interval in which the display is refreshed, if [interval()](api/Classes/classbarkeep_1_1_counter.md#function-interval) is not invoked. 

**Return**: default interval 

**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### function init

```cpp
inline void init(
    Progress * progress
)
```


### function Counter

```cpp
inline Counter(
    std::ostream & out =std::cout
)
```


-------------------------------

Updated on 2023-12-02 at 13:34:20 -0500