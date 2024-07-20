# barkeep::Composite


Creates a composite display out of two display that shows them side by side. For instance, you can combine two [Counter](api/Classes/classbarkeep_1_1_counter.md) objects to monitor two variables. 


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

## Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> template <typename... Displays\> <br></span>|  <span class="codey">  **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & head, const Displays &... tail)</span><br>Variadic constructor to combine multiple displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md).  |
| <span class="codey"> template <typename... Displays\> <br></span>|  <span class="codey">  **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(std::string delim, const Displays &... displays)</span><br>Constructor to combine multiple displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md) with a delimiter.  |
| <span class="codey"> </span>|  <span class="codey">  **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(const [Composite](api/Classes/classbarkeep_1_1_composite.md) & other)</span><br>Copy constructor clones child displays.  |
| <span class="codey"> </span>|  <span class="codey">  **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override</span> |


</span>

## Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual long </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**(bool redraw = false, const std::string & end = " ") override</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override</span> |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_composite.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

## Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::string </span> | <span class="codey"> **[delim_](api/Classes/classbarkeep_1_1_composite.md#variable-delim_)**</span>  |
| <span class="codey"> std::vector< std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > > </span> | <span class="codey"> **[displays_](api/Classes/classbarkeep_1_1_composite.md#variable-displays_)**</span>  |


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
| <span class="codey">bool </span>| <span class="codey">**[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const</span><br>Return true if the display is running.  |


</span>

**Protected Functions inherited from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)**

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">void </span>| <span class="codey">**[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**(bool redraw = false)</span><br>Display everything (message, maybe with animation, progress bar, etc).  |
| <span class="codey">long </span>| <span class="codey">**[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey">virtual void </span>| <span class="codey">**[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()</span><br>Join the display thread. Protected because python bindings need to override to handle GIL.  |


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


## Public Functions Documentation

### function `Composite`

```cpp
template <typename... Displays>
inline Composite(
    const AsyncDisplay & head,
    const Displays &... tail
)
```

Variadic constructor to combine multiple displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md). 

### function `Composite`

```cpp
template <typename... Displays>
inline Composite(
    std::string delim,
    const Displays &... displays
)
```

Constructor to combine multiple displays into a [Composite](api/Classes/classbarkeep_1_1_composite.md) with a delimiter. 

### function `Composite`

```cpp
inline Composite(
    const Composite & other
)
```

Copy constructor clones child displays. 

### function `~Composite`

```cpp
inline ~Composite()
```


### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


## Protected Functions Documentation

### function `render_`

```cpp
inline virtual long render_(
    bool redraw = false,
    const std::string & end = " "
) override
```

Render a display: animation, progress bar, etc. 

**Parameters**: 

  * **redraw** If true, display is assumed to be redrawn. This, e.g. means an [Animation](api/Classes/classbarkeep_1_1_animation.md) should not increment the still frame index. 


**Return**: Number of `\n` characters in the display. 

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

### variable `delim_`

```cpp
std::string delim_ = " ";
```


### variable `displays_`

```cpp
std::vector< std::unique_ptr< AsyncDisplay > > displays_;
```


-------------------------------