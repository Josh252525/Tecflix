# SPEC — Tecflix

## Sección Persona 3: Streaming API y V2.0
La especificación detallada y los contratos HTTP de esta sección están en [streaming-api/SPEC.md](streaming-api/SPEC.md).

Mantener las APIs existentes y no alterar `src/`, `include/` ni el CMake raíz sin acuerdo con el equipo. El servicio multimedia debe compilar con C++17 en Windows y Linux, aceptar un ID único de metadata, almacenar segmentos DASH generados por FFmpeg y ofrecer compatibilidad Shaka. El procesamiento se realiza en segundo plano. Las instancias V2 deben usar discos locales separados, un token de replicación y URLs de peers configurables. No exponer `/internal/` a clientes. Las métricas deben ser accesibles a OpenTelemetry Collector, las trazas se exportan por OTLP HTTP opcional. CI debe compilar, ejecutar pruebas y aplicar el umbral de cobertura del 90% de la biblioteca. Pruebas funcionales deben usar video real y k6 debe permitir comparar la misma carga en ambas topologías. No inventar resultados de performance.

Las especificaciones de usuarios, metadata, frontend y dashboard global deben ser agregadas por sus responsables; este archivo no sustituye sus contratos.

### Alcance de V2 y estado de verificación

- Replicación bidireccional, recuperación persistente de operaciones pendientes, propagación de eliminaciones y protección contra recreación de IDs eliminados.
- Dos balanceadores independientes, conmutación automática del reproductor de demostración y monitoreo de ambos nodos. En local se verificaron caídas de APIs, balanceadores y parejas de servicios, y recuperación posterior.
- CI Windows/Linux aprobada en `bb6fc7b`; cobertura local histórica de líneas 93.95% (fuentes de biblioteca medidas, sin main.cpp). El umbral Linux es 90%; consultar el artefacto para el valor exacto.
- Cinco optimizaciones medidas y 19 pruebas comparativas locales. No confundir procesos en un mismo host con dos servidores físicos.
- Pendiente: despliegue en dos computadoras, pruebas de rendimiento y failover físico, integración React y autorización metadata, redundancia integral de las demás APIs y observabilidad, y separación formal de versiones V1/V2.

Consultar [GUIA_PERSONA3.md](GUIA_PERSONA3.md) para operación y validación.
