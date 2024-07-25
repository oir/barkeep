# Classes



* **namespace [<span class="codey">barkeep</span>](api/Namespaces/namespacebarkeep.md)** 
    * **struct [<span class="codey">AnimationConfig</span>](api/Classes/structbarkeep_1_1_animation_config.md)** <br>Animation parameters. 
    * **class [<span class="codey">AnimationDisplay</span>](api/Classes/classbarkeep_1_1_animation_display.md)** <br>Displays a simple animation with a message. 
    * **class [<span class="codey">AsyncDisplayer</span>](api/Classes/classbarkeep_1_1_async_displayer.md)** <br>Class to handle running display loop within a worker thread. 
    * **struct [<span class="codey">AtomicTraits</span>](api/Classes/structbarkeep_1_1_atomic_traits.md)** <br>Trait class to extract underlying value type from numerics and std::atomics of numerics. 
    * **struct [<span class="codey">AtomicTraits< std::atomic< T > ></span>](api/Classes/structbarkeep_1_1_atomic_traits_3_01std_1_1atomic_3_01_t_01_4_01_4.md)** 
    * **struct [<span class="codey">BarParts</span>](api/Classes/structbarkeep_1_1_bar_parts.md)** 
    * **class [<span class="codey">BaseDisplay</span>](api/Classes/classbarkeep_1_1_base_display.md)** <br>Base class to handle all asynchronous displays. 
    * **class [<span class="codey">CompositeDisplay</span>](api/Classes/classbarkeep_1_1_composite_display.md)** <br>Creates a composite display out of multiple child displays to show them together. For instance, you can combine two Counter objects, or a Counter and a ProgressBar to concurrently monitor two variables. 
    * **struct [<span class="codey">CounterConfig</span>](api/Classes/structbarkeep_1_1_counter_config.md)** <br>Counter parameters. 
    * **class [<span class="codey">CounterDisplay</span>](api/Classes/classbarkeep_1_1_counter_display.md)** <br>Monitors and displays a single numeric variable. 
    * **class [<span class="codey">IterableBar</span>](api/Classes/classbarkeep_1_1_iterable_bar.md)** <br>A progress bar that can be used with range-based for loops, that automatically tracks the progress of the loop. 
        * **class [<span class="codey">Iterator</span>](api/Classes/classbarkeep_1_1_iterable_bar_1_1_iterator.md)** <br>[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md)'s iterator class that wraps the container's iterator. When incremented, it increments the progress index. 
    * **struct [<span class="codey">IterableBarConfig</span>](api/Classes/structbarkeep_1_1_iterable_bar_config.md)** <br>[IterableBar](api/Classes/classbarkeep_1_1_iterable_bar.md) parameters. 
    * **struct [<span class="codey">ProgressBarConfig</span>](api/Classes/structbarkeep_1_1_progress_bar_config.md)** <br>Progress bar parameters. 
    * **class [<span class="codey">ProgressBarDisplay</span>](api/Classes/classbarkeep_1_1_progress_bar_display.md)** <br>Displays a progress bar, by comparing the progress value being monitored to a given total value. Optionally reports speed. 
    * **class [<span class="codey">Speedometer</span>](api/Classes/classbarkeep_1_1_speedometer.md)** <br>Helper class to measure and display speed of progress. 
    * **class [<span class="codey">StatusDisplay</span>](api/Classes/classbarkeep_1_1_status_display.md)** <br>Status is an Animation where it is possible to update the message while the animation is running. 



-------------------------------
