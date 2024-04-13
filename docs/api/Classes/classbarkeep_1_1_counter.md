# barkeep::Counter


Monitors and displays a single numeric variable.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(Progress * progress, const [CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md) & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(const [Counter](api/Classes/classbarkeep_1_1_counter.md)< Progress > & other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< Progress > && other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**()</span><br>Write the value of progress to the output stream.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**() override</span><br>Write the value of progress with the message to the output stream.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override</span><br>Default interval in which the display is refreshed, if interval() is not invoked.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_counter.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> Progress * </span> | <span class="codey"> **[progress_](api/Classes/classbarkeep_1_1_counter.md#variable-progress_)**</span>  |
| <span class="codey"> std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< Progress > > </span> | <span class="codey"> **[speedom_](api/Classes/classbarkeep_1_1_counter.md#variable-speedom_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit_](api/Classes/classbarkeep_1_1_counter.md#variable-speed_unit_)**</span>  |
| <span class="codey"> std::stringstream </span> | <span class="codey"> **[ss_](api/Classes/classbarkeep_1_1_counter.md#variable-ss_)**</span>  |


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
| <span class="codey">void </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
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
template <typename Progress  =size_t>
class barkeep::Counter;
```

Monitors and displays a single numeric variable. 
## Public Functions Documentation

### function `Counter`

```cpp
inline Counter(
    Progress * progress,
    const CounterConfig & cfg = {}
)
```

Constructor. 

**Parameters**: 

  * **progress** Variable to be monitored and displayed 
  * **cfg** [Counter](api/Classes/classbarkeep_1_1_counter.md) parameters 


### function `Counter`

```cpp
inline Counter(
    const Counter< Progress > & other
)
```


### function `Counter`

```cpp
inline Counter(
    Counter< Progress > && other
)
```


### function `~Counter`

```cpp
inline ~Counter()
```


### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


## Protected Functions Documentation

### function `render_counts_`

```cpp
inline void render_counts_()
```

Write the value of progress to the output stream. 

### function `render_`

```cpp
inline virtual void render_() override
```

Write the value of progress with the message to the output stream. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```

Default interval in which the display is refreshed, if interval() is not invoked. 

**Return**: default interval 

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