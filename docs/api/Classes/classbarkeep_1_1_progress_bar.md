# barkeep::ProgressBar


Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle) </span>| <span class="codey">**[Style](api/Classes/classbarkeep_1_1_progress_bar.md#using-style)** </span> |


</span>

## Protected Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< Progress > </span>| <span class="codey">**[ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype)** </span> |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(Progress * progress, const [ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype) > & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< Progress > && other)</span><br>move constructor  |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(const [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< Progress > & other)</span><br>copy constructor  |
| <span class="codey"> </span>|  <span class="codey">  **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream * out = nullptr)</span><br>Compute the shape of the progress bar based on progress and write to output stream.  |
| <span class="codey"> void </span>| <span class="codey"> **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**(const std::string & end = " ")</span><br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| <span class="codey"> void </span>| <span class="codey"> **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**(const std::string & end = " ")</span><br>Write the percent completed to output stream.  |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**(const std::string & end = " ") override</span><br>Run all of the individual render methods to write everything to stream.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override</span> |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> Progress * </span> | <span class="codey"> **[progress_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-progress_)**</span>  |
| <span class="codey"> std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< Progress > > </span> | <span class="codey"> **[speedom_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-speedom_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-speed_unit_)**</span>  |
| <span class="codey"> [ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype) </span> | <span class="codey"> **[total_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-total_)**</span>  |
| <span class="codey"> [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) </span> | <span class="codey"> **[bar_parts_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-bar_parts_)**</span>  |
| <span class="codey"> constexpr size_t </span> | <span class="codey"> **[width_](api/Classes/classbarkeep_1_1_progress_bar.md#variable-width_)**</span>  |


</span>

## Additional inherited members

</span>

**Public Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out = &std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval = [Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.}, std::string message = "", std::string format = "", bool no_tty = false)</span> |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other)</span> |
| <span class="codey"></span>| <span class="codey">**[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other)</span> |
| <span class="codey">virtual </span>| <span class="codey">**[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**()</span> |
| <span class="codey">virtual void </span>| <span class="codey">**[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()</span><br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| <span class="codey">virtual void </span>| <span class="codey">**[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey">bool </span>| <span class="codey">**[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const</span> |


</span>

**Protected Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">void </span>| <span class="codey">**[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()</span><br>Display everything (message, maybe with animation, progress bar, etc).  |
| <span class="codey">long </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey">virtual void </span>| <span class="codey">**[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()</span><br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| <span class="codey">void </span>| <span class="codey">**[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const</span> |


</span>

**Protected Attributes inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">std::ostream * </span>| <span class="codey">**[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)** </span> |
| <span class="codey">std::unique_ptr< std::thread > </span>| <span class="codey">**[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)** </span> |
| <span class="codey">std::condition_variable </span>| <span class="codey">**[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)** </span> |
| <span class="codey">std::mutex </span>| <span class="codey">**[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)** </span> |
| <span class="codey">std::atomic< bool > </span>| <span class="codey">**[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)** </span> |
| <span class="codey">long </span>| <span class="codey">**[last_num_newlines_](api/Classes/classbarkeep_1_1_async_display.md#variable-last_num_newlines_)** </span> |
| <span class="codey">[Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey">**[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)** </span> |
| <span class="codey">std::string </span>| <span class="codey">**[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)** </span> |
| <span class="codey">std::string </span>| <span class="codey">**[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)** </span> |
| <span class="codey">bool </span>| <span class="codey">**[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)** </span> |


</span>

**Friends inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | <span class="codey">**[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)**</span>  |


</span>


## Detailed Description

```cpp
template <typename Progress >
class barkeep::ProgressBar;
```

Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
## Public Types Documentation

### using `Style`

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


## Protected Types Documentation

### using `ValueType`

```cpp
using barkeep::ProgressBar< Progress >::ValueType =  value_t<Progress>;
```


## Public Functions Documentation

### function `ProgressBar`

```cpp
inline ProgressBar(
    Progress * progress,
    const ProgressBarConfig< ValueType > & cfg = {}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored to measure completion 
  * **cfg** [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md) parameters 


### function `ProgressBar`

```cpp
inline ProgressBar(
    ProgressBar< Progress > && other
)
```

move constructor 

### function `ProgressBar`

```cpp
inline ProgressBar(
    const ProgressBar< Progress > & other
)
```

copy constructor 

### function `~ProgressBar`

```cpp
inline ~ProgressBar()
```


### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


## Protected Functions Documentation

### function `render_progress_bar_`

```cpp
inline void render_progress_bar_(
    std::ostream * out = nullptr
)
```

Compute the shape of the progress bar based on progress and write to output stream. 

### function `render_counts_`

```cpp
inline void render_counts_(
    const std::string & end = " "
)
```

Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total. 

### function `render_percentage_`

```cpp
inline void render_percentage_(
    const std::string & end = " "
)
```

Write the percent completed to output stream. 

### function `render_`

```cpp
inline virtual long render_(
    const std::string & end = " "
) override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::default_interval_`](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::AsyncDisplay::start`](api/Classes/classbarkeep_1_1_async_display.md#function-start)


## Protected Attributes Documentation

### variable `progress_`

```cpp
Progress * progress_;
```


### variable `speedom_`

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


### variable `speed_unit_`

```cpp
std::string speed_unit_ = "it/s";
```


### variable `total_`

```cpp
ValueType total_ {100};
```


### variable `bar_parts_`

```cpp
BarParts bar_parts_;
```


### variable `width_`

```cpp
static constexpr size_t width_ = 30;
```


-------------------------------