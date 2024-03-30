## barkeep::Animation


Displays a simple animation with a message. 


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle) </span>| <span class="codey">**[Style](api/Classes/classbarkeep_1_1_animation.md#using-style)** </span> |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [AnimationConfig](api/Classes/structbarkeep_1_1_animation_config.md) & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**(const [Animation](api/Classes/classbarkeep_1_1_animation.md) & other) = default</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Animation](api/Classes/classbarkeep_1_1_animation.md#function-animation)**([Animation](api/Classes/classbarkeep_1_1_animation.md) && ) = default</span> |
| <span class="codey"> </span>|  <span class="codey">  **[~Animation](api/Classes/classbarkeep_1_1_animation.md#function-~animation)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_animation.md#function-clone)**() const override</span> |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_animation.md#function-render_)**() override</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_)**() const override</span> |


</span>

### Additional inherited members

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
| <span class="codey">virtual void </span>| <span class="codey">**[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
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


### Public Types Documentation

#### using `Style`

```cpp
using barkeep::Animation::Style =  AnimationStyle;
```


### Public Functions Documentation

#### function `Animation`

```cpp
inline Animation(
    const AnimationConfig & cfg = {}
)
```

Constructor. 

**Parameters**: 

  * **cfg** [Animation](api/Classes/classbarkeep_1_1_animation.md) parameters 


#### function `Animation`

```cpp
Animation(
    const Animation & other
) =default
```


#### function `Animation`

```cpp
Animation(
    Animation && 
) =default
```


#### function `~Animation`

```cpp
inline ~Animation()
```


#### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function `render_`

```cpp
inline virtual void render_() override
```

Render a display: animation, progress bar, etc. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::default_interval_`](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


-------------------------------



## barkeep::AsyncDisplay


Base class to handle all asynchronous displays. 


`#include <barkeep.h>`

Inherited by [`barkeep::Animation`](api/Classes/classbarkeep_1_1_animation.md), [`barkeep::Composite`](api/Classes/classbarkeep_1_1_composite.md), [`barkeep::Counter< Progress >`](api/Classes/classbarkeep_1_1_counter.md), [`barkeep::ProgressBar< Progress >`](api/Classes/classbarkeep_1_1_progress_bar.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(std::ostream * out = &std::cout, [Duration](api/Namespaces/namespacebarkeep.md#using-duration) interval = [Duration](api/Namespaces/namespacebarkeep.md#using-duration){0.}, std::string message = "", std::string format = "", bool no_tty = false)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**(const [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) & other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-asyncdisplay)**([AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) && other)</span> |
| <span class="codey"> virtual </span>|  <span class="codey">  **[~AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md#function-~asyncdisplay)**()</span> |
| <span class="codey"> virtual void </span>|  <span class="codey">  **[show](api/Classes/classbarkeep_1_1_async_display.md#function-show)**()</span><br>Start the display. This starts writing the display in the output stream, and computing speed if applicable.  |
| <span class="codey"> virtual void </span>|  <span class="codey">  **[done](api/Classes/classbarkeep_1_1_async_display.md#function-done)**()</span><br>End the display.  |
| <span class="codey"> bool </span>|  <span class="codey">  **[running](api/Classes/classbarkeep_1_1_async_display.md#function-running)**() const</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_async_display.md#function-clone)**() const = 0</span> |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_async_display.md#function-render_)**() = 0</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)**() const = 0</span> |
| <span class="codey"> void </span>| <span class="codey"> **[display_](api/Classes/classbarkeep_1_1_async_display.md#function-display_)**()</span><br>Display everything (message, maybe with animation, progress bar, etc).  |
| <span class="codey"> void </span>| <span class="codey"> **[render_message_](api/Classes/classbarkeep_1_1_async_display.md#function-render_message_)**() const</span><br>Display the message to output stream.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_async_display.md#function-start)**()</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[join](api/Classes/classbarkeep_1_1_async_display.md#function-join)**()</span><br>Join the display thread. Protected because python bindings need to override to handle GIL.  |
| <span class="codey"> void </span>| <span class="codey"> **[ensure_not_running](api/Classes/classbarkeep_1_1_async_display.md#function-ensure_not_running)**() const</span> |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out_](api/Classes/classbarkeep_1_1_async_display.md#variable-out_)**</span>  |
| <span class="codey"> std::unique_ptr< std::thread > </span> | <span class="codey"> **[displayer_](api/Classes/classbarkeep_1_1_async_display.md#variable-displayer_)**</span>  |
| <span class="codey"> std::condition_variable </span> | <span class="codey"> **[completion_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_)**</span>  |
| <span class="codey"> std::mutex </span> | <span class="codey"> **[completion_m_](api/Classes/classbarkeep_1_1_async_display.md#variable-completion_m_)**</span>  |
| <span class="codey"> std::atomic< bool > </span> | <span class="codey"> **[complete_](api/Classes/classbarkeep_1_1_async_display.md#variable-complete_)**</span>  |
| <span class="codey"> [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span> | <span class="codey"> **[interval_](api/Classes/classbarkeep_1_1_async_display.md#variable-interval_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message_](api/Classes/classbarkeep_1_1_async_display.md#variable-message_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[format_](api/Classes/classbarkeep_1_1_async_display.md#variable-format_)**</span>  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty_](api/Classes/classbarkeep_1_1_async_display.md#variable-no_tty_)**</span>  |


</span>

### Friends

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | <span class="codey"> **[Composite](api/Classes/classbarkeep_1_1_async_display.md#friend-composite)** </span> |


</span>

### Public Functions Documentation

#### function `AsyncDisplay`

```cpp
inline AsyncDisplay(
    std::ostream * out = &std::cout,
    Duration interval = Duration{0.},
    std::string message = "",
    std::string format = "",
    bool no_tty = false
)
```


#### function `AsyncDisplay`

```cpp
inline AsyncDisplay(
    const AsyncDisplay & other
)
```


#### function `AsyncDisplay`

```cpp
inline AsyncDisplay(
    AsyncDisplay && other
)
```


#### function `~AsyncDisplay`

```cpp
inline virtual ~AsyncDisplay()
```


#### function `show`

```cpp
inline virtual void show()
```

Start the display. This starts writing the display in the output stream, and computing speed if applicable. 

#### function `done`

```cpp
inline virtual void done()
```

End the display. 

#### function `running`

```cpp
inline bool running() const
```


#### function `clone`

```cpp
virtual std::unique_ptr< AsyncDisplay > clone() const =0
```


**Reimplemented by**: [`barkeep::Animation::clone`](api/Classes/classbarkeep_1_1_animation.md#function-clone), [`barkeep::Composite::clone`](api/Classes/classbarkeep_1_1_composite.md#function-clone), [`barkeep::Counter::clone`](api/Classes/classbarkeep_1_1_counter.md#function-clone), [`barkeep::ProgressBar::clone`](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)


### Protected Functions Documentation

#### function `render_`

```cpp
virtual void render_() =0
```

Render a display: animation, progress bar, etc. 

**Reimplemented by**: [`barkeep::Animation::render_`](api/Classes/classbarkeep_1_1_animation.md#function-render_), [`barkeep::Composite::render_`](api/Classes/classbarkeep_1_1_composite.md#function-render_), [`barkeep::Counter::render_`](api/Classes/classbarkeep_1_1_counter.md#function-render_), [`barkeep::ProgressBar::render_`](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)


#### function `default_interval_`

```cpp
virtual Duration default_interval_() const =0
```


**Reimplemented by**: [`barkeep::Animation::default_interval_`](api/Classes/classbarkeep_1_1_animation.md#function-default_interval_), [`barkeep::Composite::default_interval_`](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_), [`barkeep::Counter::default_interval_`](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_), [`barkeep::ProgressBar::default_interval_`](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)


#### function `display_`

```cpp
inline void display_()
```

Display everything (message, maybe with animation, progress bar, etc). 

#### function `render_message_`

```cpp
inline void render_message_() const
```

Display the message to output stream. 

#### function `start`

```cpp
inline virtual void start()
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplemented by**: [`barkeep::Composite::start`](api/Classes/classbarkeep_1_1_composite.md#function-start), [`barkeep::Counter::start`](api/Classes/classbarkeep_1_1_counter.md#function-start), [`barkeep::ProgressBar::start`](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)


#### function `join`

```cpp
inline virtual void join()
```

Join the display thread. Protected because python bindings need to override to handle GIL. 

#### function `ensure_not_running`

```cpp
inline void ensure_not_running() const
```


### Protected Attributes Documentation

#### variable `out_`

```cpp
std::ostream * out_;
```


#### variable `displayer_`

```cpp
std::unique_ptr< std::thread > displayer_;
```


#### variable `completion_`

```cpp
std::condition_variable completion_;
```


#### variable `completion_m_`

```cpp
std::mutex completion_m_;
```


#### variable `complete_`

```cpp
std::atomic< bool > complete_ = false;
```


#### variable `interval_`

```cpp
Duration interval_ {0.0};
```


#### variable `message_`

```cpp
std::string message_;
```


#### variable `format_`

```cpp
std::string format_;
```


#### variable `no_tty_`

```cpp
bool no_tty_ = false;
```


### Friends

#### friend `Composite`

```cpp
friend class Composite(
    Composite 
);
```


-------------------------------



## barkeep::Composite


Creates a composite display out of two display that shows them side by side. For instance, you can combine two [Counter](api/Classes/classbarkeep_1_1_counter.md) objects to monitor two variables. 


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > left, std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > right)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Composite](api/Classes/classbarkeep_1_1_composite.md#function-composite)**(const [Composite](api/Classes/classbarkeep_1_1_composite.md) & other)</span><br>Copy constructor clones child displays.  |
| <span class="codey"> </span>|  <span class="codey">  **[~Composite](api/Classes/classbarkeep_1_1_composite.md#function-~composite)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_composite.md#function-clone)**() const override</span> |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_composite.md#function-render_)**() override</span><br>Render a display: animation, progress bar, etc.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_composite.md#function-default_interval_)**() const override</span> |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_composite.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span> | <span class="codey"> **[left_](api/Classes/classbarkeep_1_1_composite.md#variable-left_)**</span>  |
| <span class="codey"> std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span> | <span class="codey"> **[right_](api/Classes/classbarkeep_1_1_composite.md#variable-right_)**</span>  |


</span>

### Additional inherited members

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


### Public Functions Documentation

#### function `Composite`

```cpp
inline Composite(
    std::unique_ptr< AsyncDisplay > left,
    std::unique_ptr< AsyncDisplay > right
)
```


#### function `Composite`

```cpp
inline Composite(
    const Composite & other
)
```

Copy constructor clones child displays. 

#### function `~Composite`

```cpp
inline ~Composite()
```


#### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function `render_`

```cpp
inline virtual void render_() override
```

Render a display: animation, progress bar, etc. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::default_interval_`](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::AsyncDisplay::start`](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### Protected Attributes Documentation

#### variable `left_`

```cpp
std::unique_ptr< AsyncDisplay > left_;
```


#### variable `right_`

```cpp
std::unique_ptr< AsyncDisplay > right_;
```


-------------------------------



## barkeep::Counter


Monitors and displays a single numeric variable.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(Progress * progress, const [CounterConfig](api/Classes/structbarkeep_1_1_counter_config.md) & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**(const [Counter](api/Classes/classbarkeep_1_1_counter.md)< Progress > & other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[Counter](api/Classes/classbarkeep_1_1_counter.md#function-counter)**([Counter](api/Classes/classbarkeep_1_1_counter.md)< Progress > && other)</span> |
| <span class="codey"> </span>|  <span class="codey">  **[~Counter](api/Classes/classbarkeep_1_1_counter.md#function-~counter)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_counter.md#function-clone)**() const override</span> |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[render_counts_](api/Classes/classbarkeep_1_1_counter.md#function-render_counts_)**()</span><br>Write the value of progress to the output stream.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_counter.md#function-render_)**() override</span><br>Write the value of progress with the message to the output stream.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_counter.md#function-default_interval_)**() const override</span><br>Default interval in which the display is refreshed, if interval() is not invoked.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_counter.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

### Protected Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> Progress * </span> | <span class="codey"> **[progress_](api/Classes/classbarkeep_1_1_counter.md#variable-progress_)**</span>  |
| <span class="codey"> std::unique_ptr< [Speedometer](api/Classes/classbarkeep_1_1_speedometer.md)< Progress > > </span> | <span class="codey"> **[speedom_](api/Classes/classbarkeep_1_1_counter.md#variable-speedom_)**</span>  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit_](api/Classes/classbarkeep_1_1_counter.md#variable-speed_unit_)**</span>  |
| <span class="codey"> std::stringstream </span> | <span class="codey"> **[ss_](api/Classes/classbarkeep_1_1_counter.md#variable-ss_)**</span>  |


</span>

### Additional inherited members

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


### Detailed Description

```cpp
template <typename Progress  =size_t>
class barkeep::Counter;
```

Monitors and displays a single numeric variable. 
### Public Functions Documentation

#### function `Counter`

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


#### function `Counter`

```cpp
inline Counter(
    const Counter< Progress > & other
)
```


#### function `Counter`

```cpp
inline Counter(
    Counter< Progress > && other
)
```


#### function `~Counter`

```cpp
inline ~Counter()
```


#### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function `render_counts_`

```cpp
inline void render_counts_()
```

Write the value of progress to the output stream. 

#### function `render_`

```cpp
inline virtual void render_() override
```

Write the value of progress with the message to the output stream. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```

Default interval in which the display is refreshed, if interval() is not invoked. 

**Return**: default interval 

**Reimplements**: [`barkeep::AsyncDisplay::default_interval_`](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::AsyncDisplay::start`](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### Protected Attributes Documentation

#### variable `progress_`

```cpp
Progress * progress_ = nullptr;
```


#### variable `speedom_`

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


#### variable `speed_unit_`

```cpp
std::string speed_unit_ = "it/s";
```


#### variable `ss_`

```cpp
std::stringstream ss_;
```


-------------------------------



## barkeep::IterableBar


A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Classes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| class | **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md)**  |


</span>

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using std::atomic< size_t > </span>| <span class="codey">**[ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype)** </span> |
| <span class="codey">using [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< [ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype) > </span>| <span class="codey">**[ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype)** </span> |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md#function-iterablebar)**(Container & container, const [IterableBarConfig](api/Classes/structbarkeep_1_1_iterable_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-valuetype) > & cfg = {})</span> |
| <span class="codey"> auto </span>|  <span class="codey">  **[begin](api/Classes/classbarkeep_1_1_iterable_bar.md#function-begin)**()</span> |
| <span class="codey"> auto </span>|  <span class="codey">  **[end](api/Classes/classbarkeep_1_1_iterable_bar.md#function-end)**()</span> |


</span>

### Detailed Description

```cpp
template <typename Container >
class barkeep::IterableBar;
```

A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop. 
### Public Types Documentation

#### using `ProgressType`

```cpp
using barkeep::IterableBar< Container >::ProgressType =  std::atomic<size_t>;
```


#### using `ValueType`

```cpp
using barkeep::IterableBar< Container >::ValueType =  value_t<ProgressType>;
```


### Public Functions Documentation

#### function `IterableBar`

```cpp
inline IterableBar(
    Container & container,
    const IterableBarConfig< ValueType > & cfg = {}
)
```


#### function `begin`

```cpp
inline auto begin()
```


#### function `end`

```cpp
inline auto end()
```


-------------------------------



## barkeep::IterableBar::Iterator





`#include <barkeep.h>`

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-iterator)**(typename Container::iterator it, [ProgressType](api/Classes/classbarkeep_1_1_iterable_bar.md#using-progresstype) & idx)</span> |
| <span class="codey"> [Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & </span>|  <span class="codey">  **[operator++](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator++)**()</span> |
| <span class="codey"> bool </span>|  <span class="codey">  **[operator!=](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator!=)**(const [Iterator](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md) & other) const</span> |
| <span class="codey"> auto & </span>|  <span class="codey">  **[operator*](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md#function-operator*)**()</span> |


</span>

### Public Functions Documentation

#### function `Iterator`

```cpp
inline Iterator(
    typename Container::iterator it,
    ProgressType & idx
)
```


#### function `operator++`

```cpp
inline Iterator & operator++()
```


#### function `operator!=`

```cpp
inline bool operator!=(
    const Iterator & other
) const
```


#### function `operator*`

```cpp
inline auto & operator*()
```


-------------------------------



## barkeep::ProgressBar


Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed.  [More...](#detailed-description)


`#include <barkeep.h>`

Inherits from [`barkeep::AsyncDisplay`](api/Classes/classbarkeep_1_1_async_display.md)

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle) </span>| <span class="codey">**[Style](api/Classes/classbarkeep_1_1_progress_bar.md#using-style)** </span> |


</span>

### Protected Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using [value_t](api/Namespaces/namespacebarkeep.md#using-value_t)< Progress > </span>| <span class="codey">**[ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype)** </span> |


</span>

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(Progress * progress, const [ProgressBarConfig](api/Classes/structbarkeep_1_1_progress_bar_config.md)< [ValueType](api/Classes/classbarkeep_1_1_progress_bar.md#using-valuetype) > & cfg = {})</span><br>Constructor.  |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**([ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< Progress > && other)</span><br>move constructor  |
| <span class="codey"> </span>|  <span class="codey">  **[ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-progressbar)**(const [ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md)< Progress > & other)</span><br>copy constructor  |
| <span class="codey"> </span>|  <span class="codey">  **[~ProgressBar](api/Classes/classbarkeep_1_1_progress_bar.md#function-~progressbar)**()</span> |
| <span class="codey"> virtual std::unique_ptr< [AsyncDisplay](api/Classes/classbarkeep_1_1_async_display.md) > </span>|  <span class="codey">  **[clone](api/Classes/classbarkeep_1_1_progress_bar.md#function-clone)**() const override</span> |


</span>

### Protected Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> void </span>| <span class="codey"> **[render_progress_bar_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_progress_bar_)**(std::ostream * out = nullptr)</span><br>Compute the shape of the progress bar based on progress and write to output stream.  |
| <span class="codey"> void </span>| <span class="codey"> **[render_counts_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_counts_)**()</span><br>Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total.  |
| <span class="codey"> void </span>| <span class="codey"> **[render_percentage_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_percentage_)**()</span><br>Write the percent completed to output stream.  |
| <span class="codey"> virtual void </span>| <span class="codey"> **[render_](api/Classes/classbarkeep_1_1_progress_bar.md#function-render_)**() override</span><br>Run all of the individual render methods to write everything to stream.  |
| <span class="codey"> virtual [Duration](api/Namespaces/namespacebarkeep.md#using-duration) </span>| <span class="codey"> **[default_interval_](api/Classes/classbarkeep_1_1_progress_bar.md#function-default_interval_)**() const override</span> |
| <span class="codey"> virtual void </span>| <span class="codey"> **[start](api/Classes/classbarkeep_1_1_progress_bar.md#function-start)**() override</span><br>Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything.  |


</span>

### Protected Attributes

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

### Additional inherited members

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


### Detailed Description

```cpp
template <typename Progress >
class barkeep::ProgressBar;
```

Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
### Public Types Documentation

#### using `Style`

```cpp
using barkeep::ProgressBar< Progress >::Style =  ProgressBarStyle;
```


### Protected Types Documentation

#### using `ValueType`

```cpp
using barkeep::ProgressBar< Progress >::ValueType =  value_t<Progress>;
```


### Public Functions Documentation

#### function `ProgressBar`

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


#### function `ProgressBar`

```cpp
inline ProgressBar(
    ProgressBar< Progress > && other
)
```

move constructor 

#### function `ProgressBar`

```cpp
inline ProgressBar(
    const ProgressBar< Progress > & other
)
```

copy constructor 

#### function `~ProgressBar`

```cpp
inline ~ProgressBar()
```


#### function `clone`

```cpp
inline virtual std::unique_ptr< AsyncDisplay > clone() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::clone`](api/Classes/classbarkeep_1_1_async_display.md#function-clone)


### Protected Functions Documentation

#### function `render_progress_bar_`

```cpp
inline void render_progress_bar_(
    std::ostream * out = nullptr
)
```

Compute the shape of the progress bar based on progress and write to output stream. 

#### function `render_counts_`

```cpp
inline void render_counts_()
```

Write progress value with the total, e.g. 50/100, to output stream. Progress width is expanded (and right justified) to match width of total. 

#### function `render_percentage_`

```cpp
inline void render_percentage_()
```

Write the percent completed to output stream. 

#### function `render_`

```cpp
inline virtual void render_() override
```

Run all of the individual render methods to write everything to stream. 

**Reimplements**: [`barkeep::AsyncDisplay::render_`](api/Classes/classbarkeep_1_1_async_display.md#function-render_)


#### function `default_interval_`

```cpp
inline virtual Duration default_interval_() const override
```


**Reimplements**: [`barkeep::AsyncDisplay::default_interval_`](api/Classes/classbarkeep_1_1_async_display.md#function-default_interval_)


#### function `start`

```cpp
inline virtual void start() override
```

Start the display but do not show. This typically means start measuring speed if applicable, without displaying anything. 

**Reimplements**: [`barkeep::AsyncDisplay::start`](api/Classes/classbarkeep_1_1_async_display.md#function-start)


### Protected Attributes Documentation

#### variable `progress_`

```cpp
Progress * progress_;
```


#### variable `speedom_`

```cpp
std::unique_ptr< Speedometer< Progress > > speedom_;
```


#### variable `speed_unit_`

```cpp
std::string speed_unit_ = "it/s";
```


#### variable `total_`

```cpp
ValueType total_ {100};
```


#### variable `bar_parts_`

```cpp
BarParts bar_parts_;
```


#### variable `width_`

```cpp
static constexpr size_t width_ = 30;
```


-------------------------------



## barkeep::Speedometer


Helper class to measure and display speed of progress.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Functions

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> double </span>|  <span class="codey">  **[speed](api/Classes/classbarkeep_1_1_speedometer.md#function-speed)**()</span> |
| <span class="codey"> void </span>|  <span class="codey">  **[render_speed](api/Classes/classbarkeep_1_1_speedometer.md#function-render_speed)**(std::ostream * out, const std::string & speed_unit)</span><br>Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed.  |
| <span class="codey"> void </span>|  <span class="codey">  **[start](api/Classes/classbarkeep_1_1_speedometer.md#function-start)**()</span><br>Start computing the speed based on the amount of change in progress.  |
| <span class="codey"> </span>|  <span class="codey">  **[Speedometer](api/Classes/classbarkeep_1_1_speedometer.md#function-speedometer)**(Progress & progress, double discount)</span><br>Constructor.  |


</span>

### Detailed Description

```cpp
template <typename Progress >
class barkeep::Speedometer;
```

Helper class to measure and display speed of progress. 
### Public Functions Documentation

#### function `speed`

```cpp
inline double speed()
```


#### function `render_speed`

```cpp
inline void render_speed(
    std::ostream * out,
    const std::string & speed_unit
)
```

Write speed to given output stream. Speed is a double (written with precision 2), possibly followed by a unit of speed. 

#### function `start`

```cpp
inline void start()
```

Start computing the speed based on the amount of change in progress. 

#### function `Speedometer`

```cpp
inline Speedometer(
    Progress & progress,
    double discount
)
```

Constructor. 

**Parameters**: 

  * **progress** Reference to numeric to measure the change of. 
  * **discount** Discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-discount). If discount is 0, all increments are weighted equally. If discount is 1, only the most recent increment is considered. 


-------------------------------



## barkeep::AnimationConfig


[Animation](api/Classes/classbarkeep_1_1_animation.md) parameters. 


`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out](api/Classes/structbarkeep_1_1_animation_config.md#variable-out)** </span><br>output stream  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message](api/Classes/structbarkeep_1_1_animation_config.md#variable-message)** </span><br>message to display before the animation  |
| <span class="codey"> std::variant< [AnimationStyle](api/Namespaces/namespacebarkeep.md#enum-animationstyle), [Strings](api/Namespaces/namespacebarkeep.md#using-strings) > </span> | <span class="codey"> **[style](api/Classes/structbarkeep_1_1_animation_config.md#variable-style)** </span><br>style as AnimationStyle or custom animation as a list of strings  |
| <span class="codey"> std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > </span> | <span class="codey"> **[interval](api/Classes/structbarkeep_1_1_animation_config.md#variable-interval)** </span><br>interval in which the animation is refreshed  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty](api/Classes/structbarkeep_1_1_animation_config.md#variable-no_tty)** </span><br>no-tty mode if true (no \r, slower default refresh)  |
| <span class="codey"> bool </span> | <span class="codey"> **[show](api/Classes/structbarkeep_1_1_animation_config.md#variable-show)** </span><br>show the animation immediately after construction  |


</span>

### Public Attributes Documentation

#### variable `out`

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable `message`

```cpp
std::string message = "";
```

message to display before the animation 

#### variable `style`

```cpp
std::variant< AnimationStyle, Strings > style = Ellipsis;
```

style as AnimationStyle or custom animation as a list of strings 

#### variable `interval`

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the animation is refreshed 

#### variable `no_tty`

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

#### variable `show`

```cpp
bool show = true;
```

show the animation immediately after construction 

-------------------------------



## barkeep::AtomicTraits


Trait class to extract underlying value type from numerics and std::atomics of numerics.  [More...](#detailed-description)


`#include <barkeep.h>`

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using T </span>| <span class="codey">**[value_type](api/Classes/structbarkeep_1_1_atomic_traits.md#using-value_type)** </span> |


</span>

### Detailed Description

```cpp
template <typename T >
struct barkeep::AtomicTraits;
```

Trait class to extract underlying value type from numerics and std::atomics of numerics. 
### Public Types Documentation

#### using `value_type`

```cpp
using barkeep::AtomicTraits< T >::value_type =  T;
```


-------------------------------



## barkeep::AtomicTraits< std::atomic< T > >


 [More...](#detailed-description)


`#include <barkeep.h>`

### Public Types

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey">using T </span>| <span class="codey">**[value_type](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md#using-value_type)** </span> |


</span>

### Detailed Description

```cpp
template <typename T >
struct barkeep::AtomicTraits< std::atomic< T > >;
```

### Public Types Documentation

#### using `value_type`

```cpp
using barkeep::AtomicTraits< std::atomic< T > >::value_type =  T;
```


-------------------------------



## barkeep::BarParts





`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::string </span> | <span class="codey"> **[left](api/Classes/structbarkeep_1_1_bar_parts.md#variable-left)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[right](api/Classes/structbarkeep_1_1_bar_parts.md#variable-right)** </span> |
| <span class="codey"> [Strings](api/Namespaces/namespacebarkeep.md#using-strings) </span> | <span class="codey"> **[fill](api/Classes/structbarkeep_1_1_bar_parts.md#variable-fill)** </span> |
| <span class="codey"> [Strings](api/Namespaces/namespacebarkeep.md#using-strings) </span> | <span class="codey"> **[empty](api/Classes/structbarkeep_1_1_bar_parts.md#variable-empty)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[incomplete_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-incomplete_left_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[complete_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-complete_left_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[middle_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-middle_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-right_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[percent_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-percent_left_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[percent_right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-percent_right_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[value_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-value_left_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[value_right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-value_right_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_left_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-speed_left_modifier)** </span> |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_right_modifier](api/Classes/structbarkeep_1_1_bar_parts.md#variable-speed_right_modifier)** </span> |


</span>

### Public Attributes Documentation

#### variable `left`

```cpp
std::string left;
```


#### variable `right`

```cpp
std::string right;
```


#### variable `fill`

```cpp
Strings fill;
```


#### variable `empty`

```cpp
Strings empty;
```


#### variable `incomplete_left_modifier`

```cpp
std::string incomplete_left_modifier = "";
```


#### variable `complete_left_modifier`

```cpp
std::string complete_left_modifier = "";
```


#### variable `middle_modifier`

```cpp
std::string middle_modifier = "";
```


#### variable `right_modifier`

```cpp
std::string right_modifier = "";
```


#### variable `percent_left_modifier`

```cpp
std::string percent_left_modifier = "";
```


#### variable `percent_right_modifier`

```cpp
std::string percent_right_modifier = "";
```


#### variable `value_left_modifier`

```cpp
std::string value_left_modifier = "";
```


#### variable `value_right_modifier`

```cpp
std::string value_right_modifier = "";
```


#### variable `speed_left_modifier`

```cpp
std::string speed_left_modifier = "";
```


#### variable `speed_right_modifier`

```cpp
std::string speed_right_modifier = "";
```


-------------------------------



## barkeep::CounterConfig


[Counter](api/Classes/classbarkeep_1_1_counter.md) parameters. 


`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out](api/Classes/structbarkeep_1_1_counter_config.md#variable-out)** </span><br>output stream  |
| <span class="codey"> std::string </span> | <span class="codey"> **[format](api/Classes/structbarkeep_1_1_counter_config.md#variable-format)** </span><br>format string to format entire counter  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message](api/Classes/structbarkeep_1_1_counter_config.md#variable-message)** </span><br>message to display with the counter  |
| <span class="codey"> std::optional< double > </span> | <span class="codey"> **[speed](api/Classes/structbarkeep_1_1_counter_config.md#variable-speed)** </span><br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit](api/Classes/structbarkeep_1_1_counter_config.md#variable-speed_unit)** </span><br>unit of speed text next to speed  |
| <span class="codey"> std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > </span> | <span class="codey"> **[interval](api/Classes/structbarkeep_1_1_counter_config.md#variable-interval)** </span><br>interval in which the counter is refreshed  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty](api/Classes/structbarkeep_1_1_counter_config.md#variable-no_tty)** </span><br>no-tty mode if true (no \r, slower default refresh)  |
| <span class="codey"> bool </span> | <span class="codey"> **[show](api/Classes/structbarkeep_1_1_counter_config.md#variable-show)** </span><br>show the counter immediately after construction  |


</span>

### Public Attributes Documentation

#### variable `out`

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable `format`

```cpp
std::string format = "";
```

format string to format entire counter 

#### variable `message`

```cpp
std::string message = "";
```

message to display with the counter 

#### variable `speed`

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

#### variable `speed_unit`

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed 

#### variable `interval`

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the counter is refreshed 

#### variable `no_tty`

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

#### variable `show`

```cpp
bool show = true;
```

show the counter immediately after construction 

-------------------------------



## barkeep::IterableBarConfig


 [More...](#detailed-description)


`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-out)** </span><br>output stream  |
| <span class="codey"> std::string </span> | <span class="codey"> **[format](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-format)** </span><br>format string for the entire progress bar  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-message)** </span><br>message to display with the bar  |
| <span class="codey"> std::optional< double > </span> | <span class="codey"> **[speed](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed)** </span><br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-speed_unit)** </span><br>unit of speed text next to speed  |
| <span class="codey"> [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle) </span> | <span class="codey"> **[style](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-style)** </span><br>style of progress bar  |
| <span class="codey"> std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > </span> | <span class="codey"> **[interval](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-interval)** </span><br>interval in which the progress bar is refreshed  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty](api/Classes/structbarkeep_1_1_iterable_bar_config.md#variable-no_tty)** </span><br>no-tty mode if true (no \r, slower default refresh)  |


</span>

### Detailed Description

```cpp
template <typename ValueType >
struct barkeep::IterableBarConfig;
```

### Public Attributes Documentation

#### variable `out`

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable `format`

```cpp
std::string format = "";
```

format string for the entire progress bar 

#### variable `message`

```cpp
std::string message = "";
```

message to display with the bar 

#### variable `speed`

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

#### variable `speed_unit`

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed 

#### variable `style`

```cpp
ProgressBarStyle style = Blocks;
```

style of progress bar 

#### variable `interval`

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the progress bar is refreshed 

#### variable `no_tty`

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

-------------------------------



## barkeep::ProgressBarConfig


 [More...](#detailed-description)


`#include <barkeep.h>`

### Public Attributes

<span class="api-table">

|                | Name           |
| -------------- | -------------- |
| <span class="codey"> std::ostream * </span> | <span class="codey"> **[out](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-out)** </span><br>output stream  |
| <span class="codey"> ValueType </span> | <span class="codey"> **[total](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-total)** </span><br>total amount of work for a full bar  |
| <span class="codey"> std::string </span> | <span class="codey"> **[format](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-format)** </span><br>format string for the entire progress bar  |
| <span class="codey"> std::string </span> | <span class="codey"> **[message](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-message)** </span><br>message to display with the bar  |
| <span class="codey"> std::optional< double > </span> | <span class="codey"> **[speed](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-speed)** </span><br>Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed.  |
| <span class="codey"> std::string </span> | <span class="codey"> **[speed_unit](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-speed_unit)** </span><br>unit of speed text next to speed  |
| <span class="codey"> std::variant< [ProgressBarStyle](api/Namespaces/namespacebarkeep.md#enum-progressbarstyle), [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) > </span> | <span class="codey"> **[style](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-style)** </span><br>progress bar style, or custom style as [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md) |
| <span class="codey"> std::variant< [Duration](api/Namespaces/namespacebarkeep.md#using-duration), double > </span> | <span class="codey"> **[interval](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-interval)** </span><br>interval in which the progress bar is refreshed  |
| <span class="codey"> bool </span> | <span class="codey"> **[no_tty](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-no_tty)** </span><br>no-tty mode if true (no \r, slower default refresh)  |
| <span class="codey"> bool </span> | <span class="codey"> **[show](api/Classes/structbarkeep_1_1_progress_bar_config.md#variable-show)** </span><br>show the progress bar immediately after construction  |


</span>

### Detailed Description

```cpp
template <typename ValueType >
struct barkeep::ProgressBarConfig;
```

### Public Attributes Documentation

#### variable `out`

```cpp
std::ostream * out = &std::cout;
```

output stream 

#### variable `total`

```cpp
ValueType total = 100;
```

total amount of work for a full bar 

#### variable `format`

```cpp
std::string format = "";
```

format string for the entire progress bar 

#### variable `message`

```cpp
std::string message = "";
```

message to display with the bar 

#### variable `speed`

```cpp
std::optional< double > speed = std::nullopt;
```

Speed discount factor in [0, 1] to use in computing the speed. Previous increments are weighted by (1-speed). If speed is 0, all increments are weighed equally. If speed is 1, only the most recent increment is considered. If speed is `std::nullopt`, speed is not computed. 

#### variable `speed_unit`

```cpp
std::string speed_unit = "it/s";
```

unit of speed text next to speed 

#### variable `style`

```cpp
std::variant< ProgressBarStyle, BarParts > style = Blocks;
```

progress bar style, or custom style as [BarParts](api/Classes/structbarkeep_1_1_bar_parts.md)

#### variable `interval`

```cpp
std::variant< Duration, double > interval = Duration{0.};
```

interval in which the progress bar is refreshed 

#### variable `no_tty`

```cpp
bool no_tty = false;
```

no-tty mode if true (no \r, slower default refresh) 

#### variable `show`

```cpp
bool show = true;
```

show the progress bar immediately after construction 

-------------------------------

Updated on 2024-03-29 at 22:38:09 -0400