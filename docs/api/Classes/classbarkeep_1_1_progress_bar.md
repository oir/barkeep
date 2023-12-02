# barkeep::ProgressBar


Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using ProgressBarStyle | **[Style](api/Classes/classbarkeep_1_1_progress_bar.md#using-style)**  |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, std::ostream & out =std::cout)<br>Constructor.  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other)<br>move constructor  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other)<br>copy constructor  |
| | **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[show](api/Classes/classbarkeep_1_1_progress_bar.md#function-show)**() override<br>Start displaying the bar.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed)**(std::optional< [double](api/Classes/classbarkeep_1_1_counter.md) > discount)<br>Set how to compute speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[speed_unit](api/Classes/classbarkeep_1_1_progress_bar.md#function-speed_unit)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set unit of speed text next to speed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[total](api/Classes/classbarkeep_1_1_progress_bar.md#function-total)**([ValueType](api/Classes/classbarkeep_1_1_counter.md) tot)<br>Set total amount of work to be done, for the progress bar to be full.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[style](api/Classes/classbarkeep_1_1_progress_bar.md#function-style)**(Style sty)<br>Set progress bar style.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[message](api/Classes/classbarkeep_1_1_progress_bar.md#function-message)**([const](api/Classes/classbarkeep_1_1_counter.md) std::string & msg)<br>Set message to be displayed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**(Duration pd)<br>Set interval in which the display is refreshed.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[interval](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval)**([double](api/Classes/classbarkeep_1_1_counter.md) pd)<br>Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval) to accept a double argument.  |
| [auto](api/Classes/classbarkeep_1_1_counter.md) & | **[no_tty](api/Classes/classbarkeep_1_1_progress_bar.md#function-no_tty)**()<br>Enable no-tty mode.  |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream & out)<br>Compute the shape of the progress bar based on progress and write to output stream.  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**(std::ostream & out)<br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**(std::ostream & out)<br>Write the percent completed to output stream.  |
| virtual [size_t](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**(std::ostream & out) override<br>Run all of the individual render methods to write everything to stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[init](api/Classes/classbarkeep_1_1_progress_bar.md#function-init)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress) |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(std::ostream & out =std::cout) |


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
template <typenameProgress >
class barkeep::ProgressBar;
```

Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
## Public Types Documentation

### using Style

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


## Public Functions Documentation

### function ProgressBar

```cpp
inline ProgressBar(
    Progress * progress,
    std::ostream & out =std::cout
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored to measure completion 
  * **out** Output stream to write to 


### function ProgressBar

```cpp
inline ProgressBar(
    ProgressBar< Progress > && other
)
```

move constructor 

### function ProgressBar

```cpp
inline ProgressBar(
    constProgressBar< Progress > & other
)
```

copy constructor 

### function ~ProgressBar

```cpp
inline ~ProgressBar()
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

Start displaying the bar. 

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

### function total

```cpp
inline auto & total(
    ValueType tot
)
```

Set total amount of work to be done, for the progress bar to be full. 

**Parameters**: 

  * **tot** total amount of work 


**Return**: reference to self 

### function style

```cpp
inline auto & style(
    Style sty
)
```

Set progress bar style. 

**Parameters**: 

  * **sty** Style 


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

Overload of [interval(Duration)](api/Classes/classbarkeep_1_1_progress_bar.md#function-interval) to accept a double argument. 

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

### function render_progress_bar_

```cpp
inline size_t render_progress_bar_(
    std::ostream & out
)
```

Compute the shape of the progress bar based on progress and write to output stream. 

### function render_counts_

```cpp
inline size_t render_counts_(
    std::ostream & out
)
```

Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total. 

### function render_percentage_

```cpp
inline size_t render_percentage_(
    std::ostream & out
)
```

Write the percent completed to output stream. 

### function render_

```cpp
inline virtual size_t render_(
    std::ostream & out
) override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### function init

```cpp
inline void init(
    Progress * progress
)
```


### function ProgressBar

```cpp
inline ProgressBar(
    std::ostream & out =std::cout
)
```


-------------------------------

Updated on 2023-12-02 at 13:34:20 -0500