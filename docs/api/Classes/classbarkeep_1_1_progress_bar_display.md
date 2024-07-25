# barkeep::ProgressBarDisplay


Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [`barkeep::BaseDisplay`](api/Classes/classbarkeep_1_1_base_display.md)

## Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle) </span>| <span class="codey">**[Style](api/Classes/classbarkeep_1_1_progress_bar_display.md#using-style)** </span> |


</span>

## Protected Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< Progress > </span>| <span class="codey">**[ValueType](api/Classes/classbarkeep_1_1_progress_bar_display.md#using-valuetype)** </span> |


</span>

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-progressbardisplay)**(Progress * progress, const [ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_progress_bar_display.md#using-valuetype) > & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[~ProgressBarDisplay](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-~progressbardisplay)**()</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-render_progress_bar_)**(std::ostream * out)</span><br>Compute the shape of the progress bar based on progress and write to output stream.  |
| <span class="codey"> void </span>| <span class="codey"> **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-render_counts_)**(const std::string & end = " ")</span><br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| <span class="codey"> void </span>| <span class="codey"> **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-render_percentage_)**(const std::string & end = " ")</span><br>Write the percent completed to output stream.  |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-render_)**(bool  = false, const std::string & end = " ") override</span><br>Run all of the individual render methods to write everything to stream.  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-default_interval_)**(bool no_tty) const</span> |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_progress_bar_display.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> Progress * </span> | <span class="codey"> **[progress_](api/Classes/classbarkeep_1_1_progress_bar_display.md#variable-progress_)**</span>  |
| <span class="codey"> std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< Progress > > </span> | <span class="codey"> **[speedom_](api/Classes/classbarkeep_1_1_progress_bar_display.md#variable-speedom_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit_](api/Classes/classbarkeep_1_1_progress_bar_display.md#variable-speed_unit_)**</span>  |
| <span class="codey"> [ValueType](api/Classes/classbarkeep_1_1_progress_bar_display.md#using-valuetype) </span> | <span class="codey"> **[total_](api/Classes/classbarkeep_1_1_progress_bar_display.md#variable-total_)**</span>  |
| <span class="codey"> [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) </span> | <span class="codey"> **[bar_parts_](api/Classes/classbarkeep_1_1_progress_bar_display.md#variable-bar_parts_)**</span>  |
| <span class="codey"> constexpr size_t </span> | <span class="codey"> **[width_](api/Classes/classbarkeep_1_1_progress_bar_display.md#variable-width_)**</span>  |


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
template <typename Progress >
class barkeep::ProgressBarDisplay;
```

Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
## Public Types Documentation

### using `Style`

```cpp
using barkeep::ProgressBarDisplay< Progress >::Style =  ProgressBarStyle;
```


## Protected Types Documentation

### using `ValueType`

```cpp
using barkeep::ProgressBarDisplay< Progress >::ValueType =  value_t<Progress>;
```


## Public Functions Documentation

### function `ProgressBarDisplay`

```cpp
inline ProgressBarDisplay(
    Progress * progress,
    const ProgressBarConfig< ValueType > & cfg = {}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored to measure completion 
  * **cfg** ProgressBar parameters 


### function `~ProgressBarDisplay`

```cpp
inline ~ProgressBarDisplay()
```


## Protected Functions Documentation

### function `render_progress_bar_`

```cpp
inline void render_progress_bar_(
    std::ostream * out
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
    bool  = false,
    const std::string & end = " "
) override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [`barkeep::BaseDisplay::render_`](api/Classes/classbarkeep_1_1_base_display.md#function-render_)


### function `default_interval_`

```cpp
inline Duration default_interval_(
    bool no_tty
) const
```


### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::BaseDisplay::start`](api/Classes/classbarkeep_1_1_base_display.md#function-start)


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