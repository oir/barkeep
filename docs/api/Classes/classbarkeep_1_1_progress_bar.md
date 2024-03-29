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

## Protected Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| using value_t< [Progress](api/Classes/classbarkeep_1_1_counter.md) > | **[ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype)**  |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([Progress](api/Classes/classbarkeep_1_1_counter.md) * progress, [const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_counter.md) > & cfg ={})<br>Constructor.  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > && other)<br>move constructor  |
| | **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([const](api/Classes/classbarkeep_1_1_counter.md)[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > & other)<br>copy constructor  |
| | **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**() |
| virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > | **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream * out =[nullptr](api/Classes/classbarkeep_1_1_counter.md))<br>Compute the shape of the progress bar based on progress and write to output stream.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**()<br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**()<br>Write the percent completed to output stream.  |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**() override<br>Run all of the individual render methods to write everything to stream.  |
| virtual Duration | **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override |
| virtual [void](api/Classes/classbarkeep_1_1_counter.md) | **[start](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)**() override<br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| [Progress](api/Classes/classbarkeep_1_1_counter.md) * | **[progress_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-progress_)**  |
| std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< [Progress](api/Classes/classbarkeep_1_1_counter.md) > > | **[speedom_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-speedom_)**  |
| std::string | **[speed_unit_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-speed_unit_)**  |
| [ValueType](api/Classes/classbarkeep_1_1_counter.md) | **[total_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-total_)**  |
| [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) | **[bar_parts_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-bar_parts_)**  |
| [constexpr](api/Classes/classbarkeep_1_1_counter.md)[size_t](api/Classes/classbarkeep_1_1_counter.md) | **[width_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-width_)**  |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [barkeep::AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| | **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out =&std::cout, Duration interval =Duration{0.}, std::string message ="", std::string format ="", [bool](api/Classes/classbarkeep_1_1_counter.md) no_tty =[false](api/Classes/classbarkeep_1_1_counter.md)) |
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
template <typenameProgress >
class barkeep::ProgressBar;
```

Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
## Public Types Documentation

### using Style

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


## Protected Types Documentation

### using ValueType

```cpp
using barkeep::ProgressBar< Progress >::ValueType =  value_t<Progress>;
```


## Public Functions Documentation

### function ProgressBar

```cpp
inline ProgressBar(
    Progress * progress,
    constProgressBarConfig< ValueType > & cfg ={}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored to measure completion 
  * **cfg** [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md) parameters 


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


## Protected Functions Documentation

### function render_progress_bar_

```cpp
inline void render_progress_bar_(
    std::ostream * out =nullptr
)
```

Compute the shape of the progress bar based on progress and write to output stream. 

### function render_counts_

```cpp
inline void render_counts_()
```

Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total. 

### function render_percentage_

```cpp
inline void render_percentage_()
```

Write the percent completed to output stream. 

### function render_

```cpp
inline virtual void render_() override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [barkeep::AsyncDisplay::render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function default_interval_

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [barkeep::AsyncDisplay::default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### function start

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [barkeep::AsyncDisplay::start](api/Classes/classbarkeep_1_1_async_display.md#function-start)


## Protected Attributes Documentation

### variable progress_

```cpp
Progress * progress_;
```


### variable speedom_

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


### variable speed_unit_

```cpp
std::string speed_unit_ = "it/s";
```


### variable total_

```cpp
ValueType total_ {100};
```


### variable bar_parts_

```cpp
BarParts bar_parts_;
```


### variable width_

```cpp
static constexprsize_t width_ = 30;
```


-------------------------------

Updated on 2024-03-28 at 21:56:22 -0400